#include "head.h"

int main()
{     
    boost::timer::auto_cpu_timer t;  //计算程序运行时间
    t.start();
    //t.start();                                      //开始计时
    pDEC dec;//用于接收分解指针只传递一个数据大小
    
    //初始化小波分解所需要的系数，第一个参数为DBn小波，第二个系数是信号的行数，第三个系数是信号的列数
    DWT dwt(4,9,32,7681,0,32,40,32);//参数说明，，第一参数是dbn小波，第二个参数是分解n层，第三个参数是有几个信号，第四个参数是信号长度，第五个参数是读文件模式0读EEG，1读label
    //第六个参数是读那个文件夹，第七个参数是文件夹下那个文件，第八个参数重构是的txt哪一行,第九个参数为频率
    //初始化系数矩阵的信息
    Matrix max(dwt.getDWT_DBN());
    max.matrix();
    std::cout << "系数矩阵" << std::endl;
    max.Print_matrix();
    //进行读文件操作
//分解操作  
    for(int i = 1; i <= dwt.getDWT_file_m(); ++i)//循环32个文件夹   
    {
        for(int j = 1; j <= dwt.getDWT_file_n(); ++j)//循环40个文件       
        {
            rwDate rwd(dwt.getDWT_DBN(),dwt.getDWT_data_row(),dwt.getDWT_data_line(),i,j,dwt.getDWT_mode());
            rwd.ReadDate();
            //rwd.Print_rwDate();
            //执行小波分解过程，小波分解的参数有三个，第一个是分解层数，第二个是需要分解的信号，第三个是系数矩阵
            TF tf(dwt.getDWT_DBN(),dwt.getDWT_DBN_N(),dwt.getDWT_data_row(),dwt.getDWT_data_line(),i,j,dwt.getDWT_mode());
            tf.transform(rwd.getRaw_Data(),max.getMatrix());
            dec = tf.getTransform_DEC();       
        }        
    }                  

    boost::thread t_HtoD0(boost::bind(thread_Alpha,dwt,max,dec));
    boost::thread t_HtoD1(boost::bind(thread_Beta,dwt,max,dec));
    boost::thread t_HtoD2(boost::bind(thread_Delta,dwt,max,dec));
    boost::thread t_HtoD3(boost::bind(thread_Theta,dwt,max,dec));

    t_HtoD0.join();
    t_HtoD1.join();
    t_HtoD2.join();
    t_HtoD3.join();
    
    std::cout << t.format() << std::endl; 
    return 0;
}

