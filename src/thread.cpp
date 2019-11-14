#include "head.h"

void thread_Alpha(DWT dwt,Matrix max, pDEC dec)
{
    for(int i = 1; i <=  dwt.getDWT_file_m(); ++i)
    {
        for(int j = 1; j <= dwt.getDWT_file_n(); ++j)
        {
            for(int k = 1; k <= dwt.getDWT_file_txt(); ++k)
            {
                RWDATE_REF rwref(dwt.getDWT_DBN_N(),i,j,k,dec); 
                rwref.ReadDate_ref();
                //rwref.Print_rwDate_ref();
                RTF rtf(dwt.getDWT_DBN(),dwt.getDWT_DBN_N(),rwref.getFile_data_line(),rwref.getFile_m_ref(),rwref.getFile_n_ref(),128);                
                rtf.Reverse_transform_init(max.getMatrix(),"Alpha");//初始化重构函数
                rtf.Reverse_transform(rwref.getRaw_Data_ref(),rwref.getFile_txt_ref());             
            }
        } 
    }
}

void thread_Beta(DWT dwt,Matrix max, pDEC dec)
{
    for(int i = 1; i <=  dwt.getDWT_file_m(); ++i)
    {
        for(int j = 1; j <= dwt.getDWT_file_n(); ++j)
        {
            for(int k = 1; k <= dwt.getDWT_file_txt(); ++k)
            {
                RWDATE_REF rwref(dwt.getDWT_DBN_N(),i,j,k,dec); 
                rwref.ReadDate_ref();
                //rwref.Print_rwDate_ref();
                RTF rtf(dwt.getDWT_DBN(),dwt.getDWT_DBN_N(),rwref.getFile_data_line(),rwref.getFile_m_ref(),rwref.getFile_n_ref(),128);                
                rtf.Reverse_transform_init(max.getMatrix(),"Beta");//初始化重构函数
                rtf.Reverse_transform(rwref.getRaw_Data_ref(),rwref.getFile_txt_ref());            
            }
        }
    }     
}

void thread_Delta(DWT dwt,Matrix max, pDEC dec)
{
    for(int i = 1; i <=  dwt.getDWT_file_m(); ++i)
    {
        for(int j = 1; j <= dwt.getDWT_file_n(); ++j)
        {
            for(int k = 1; k <= dwt.getDWT_file_txt(); ++k)
            {
                RWDATE_REF rwref(dwt.getDWT_DBN_N(),i,j,k,dec); 
                rwref.ReadDate_ref();
                //rwref.Print_rwDate_ref();
                RTF rtf(dwt.getDWT_DBN(),dwt.getDWT_DBN_N(),rwref.getFile_data_line(),rwref.getFile_m_ref(),rwref.getFile_n_ref(),128);                
                rtf.Reverse_transform_init(max.getMatrix(),"Delta");//初始化重构函数
                rtf.Reverse_transform(rwref.getRaw_Data_ref(),rwref.getFile_txt_ref());           
            }
        }
    }  
}

void thread_Theta(DWT dwt,Matrix max, pDEC dec)
{
    for(int i = 1; i <=  dwt.getDWT_file_m(); ++i)
    {
        for(int j = 1; j <= dwt.getDWT_file_n(); ++j)
        {
            for(int k = 1; k <= dwt.getDWT_file_txt(); ++k)
            {
                RWDATE_REF rwref(dwt.getDWT_DBN_N(),i,j,k,dec); 
                rwref.ReadDate_ref();
                //rwref.Print_rwDate_ref();
                RTF rtf(dwt.getDWT_DBN(),dwt.getDWT_DBN_N(),rwref.getFile_data_line(),rwref.getFile_m_ref(),rwref.getFile_n_ref(),128);                
                rtf.Reverse_transform_init(max.getMatrix(),"Theta");//初始化重构函数
                rtf.Reverse_transform(rwref.getRaw_Data_ref(),rwref.getFile_txt_ref());  
            } 
        }
    } 
    
}