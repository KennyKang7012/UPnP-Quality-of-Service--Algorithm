#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#define SERVICE_TYPE 3             	// 提供服務的種類  0 :VOIP  1:FTP  2:Streaming
#define SERVICE_TNUM 100           	// 最大服務數 
#define MAX_BW 10000                // 最大頻寬 

int rand1[100]={1,2,1,1,2,1,2,0,0,1,2,0,2,2,2,1,1,0,1,0,2,1,1,0,2,0,1,1,0,0,0,0,1,1,0,2,1,0,2,1,1,2,1,0,2,1,2,0,0,0,2,1,1,1,2,1,0,1,0,0,0,1,2,2,0,1,0,2,2,2,2,0,1,0,0,1,0,1,1,2,0,0,1,2,0,0,0,1,2,1,0,0,2,0,1,2,0,1,0,0};
int rand2[100]={1,1,2,2,1,0,1,0,0,1,0,2,1,2,2,2,2,0,1,1,0,2,1,0,0,2,1,0,0,1,1,2,1,1,0,1,2,1,2,2,2,2,2,1,2,0,0,2,1,1,1,2,0,1,0,2,0,2,0,1,2,0,1,0,1,2,0,0,1,0,2,1,1,1,2,2,1,0,1,2,1,1,2,1,2,1,1,0,2,0,2,1,0,1,1,2,0,1,2,2};
int rand3[100]={2,1,2,2,0,2,1,2,0,0,2,1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,0,2,2,0,0,0,0,0,0,1,0,0,2,2,2,2,1,0,1,0,0,0,2,1,2,0,1,0,0,0,0,2,1,0,0,2,0,0,1,0,2,2,0,1,2,0,1,0,1,2,1,2,1,0,0,1,1,0,2,0,0,1,2,1,1,0,2,0,0,1,2,2,2,2};
int rand4[100]={1,2,1,1,2,0,1,2,1,0,2,0,0,1,0,1,1,2,2,0,1,0,0,1,0,2,2,2,1,1,1,2,1,1,1,2,0,0,2,1,2,1,0,2,1,1,0,2,2,2,0,1,1,1,0,2,0,1,0,2,1,2,2,2,2,1,2,2,1,2,2,1,0,0,0,1,0,1,1,1,1,1,0,2,0,2,0,2,0,1,1,0,0,2,1,0,2,0,0,1};
int rand5[100]={0,1,0,2,1,1,0,0,1,2,0,2,0,1,2,0,2,2,0,1,2,2,2,2,2,0,0,0,0,2,0,0,1,2,0,0,1,0,1,1,1,2,1,1,2,1,1,1,0,1,2,2,0,1,0,0,0,2,2,2,2,2,2,0,0,1,1,1,2,0,1,2,2,2,0,1,2,2,1,2,0,1,0,0,1,1,2,1,2,0,1,0,0,1,0,1,0,0,1,0};

long int filesize1[100]={402,20403,14404,10401,12406,2400,405,-1,-1,14403,36406,-1,8409,24405,4406,16404,408,-1,10402,-1,400,401,18405,-1,32404,-1,402,4406,-1,-1,-1,-1,18405,10402,-1,36407,16402,-1,36406,2406,407,405,8405,-1,4407,10404,28403,-1,-1,-1,403,10406,12405,14409,16405,16405,-1,18402,-1,-1,-1,10406,28409,16400,-1,18406,-1,20407,28405,36405,4409,-1,14408,-1,-1,12400,-1,12405,400,12401,-1,-1,404,32400,-1,-1,-1,12403,16403,14405,-1,-1,36400,-1,14401,4407,-1,16409,-1,-1};
long int filesize2[100]={4407,2404,20405,4400,6407,-1,8409,-1,-1,402,-1,408,405,32400,16400,16403,28409,-1,6408,18408,-1,4403,4407,-1,-1,24401,18404,-1,-1,16408,12404,36400,12404,8402,-1,16402,8408,10408,20401,8405,28401,32409,36406,14406,403,-1,-1,4404,406,10404,16400,24408,-1,16409,-1,16406,-1,8405,-1,408,36407,-1,407,-1,18400,36405,-1,-1,6408,-1,24405,6400,12407,14401,400,16405,10404,-1,8409,36400,16401,18400,28405,10403,16404,403,14400,-1,12402,-1,20401,4408,-1,6403,14402,32407,-1,12404,8408,12401};
long int filesize3[100]={16404,14401,28407,20408,-1,16409,2404,20405,-1,-1,4407,8405,401,10404,-1,406,16408,401,-1,-1,4400,-1,401,-1,2409,400,-1,36408,4404,-1,-1,-1,-1,-1,-1,2401,-1,-1,4405,16406,407,20402,2408,-1,12407,-1,-1,-1,24400,6401,20405,-1,6401,-1,-1,-1,-1,32402,8404,-1,-1,4403,-1,-1,16403,-1,12406,4406,-1,4405,16406,-1,2407,-1,2406,24407,16409,20405,16403,-1,-1,14402,6402,-1,8405,-1,-1,2401,20404,8406,14403,-1,28406,-1,-1,12403,407,28409,32401,12404};
long int filesize4[100]={8401,12402,12402,10406,32401,-1,18403,24406,400,-1,16407,-1,-1,18401,-1,16402,18402,4407,404,-1,16406,-1,-1,10402,-1,16409,400,36408,4405,4403,10401,24404,8403,12403,16401,8401,-1,-1,28402,10402,20405,16403,-1,24409,8400,10404,-1,36405,403,36407,-1,4404,12402,18402,-1,4404,-1,14406,-1,36400,402,24408,28408,32402,407,2401,28401,12406,12408,16409,24403,2406,-1,-1,-1,14403,-1,10404,18404,18401,2404,4402,-1,20404,-1,12407,-1,24400,-1,18408,2401,-1,-1,4402,8409,-1,36401,-1,-1,4409};
long int filesize5[100]={-1,12402,-1,20407,10405,4405,-1,-1,10402,36409,-1,32403,-1,16405,4401,-1,406,12406,-1,403,8409,16405,28409,8406,403,-1,-1,-1,-1,8404,-1,-1,10408,16409,-1,-1,18404,-1,14404,12402,14408,12409,14402,14400,28404,6400,6404,403,-1,6401,32404,8404,-1,8402,-1,-1,-1,12404,16400,20400,8400,36402,4406,-1,-1,2408,4401,16407,36409,-1,6409,403,16409,12404,-1,2408,36408,32406,4408,16402,-1,2402,-1,-1,12406,6408,36405,8403,36403,-1,10402,-1,-1,12407,-1,6403,-1,-1,2409,-1};


typedef struct service_item {
		int flag;					// 0:代表離開或是無人使用 , 1:代表有人使用中
		int service;				// 服務
		float bandwidth;			// 每項服務中每個使用者所佔用的頻寬	= Breal
		float release_bw;           // 要釋放的空間大小(佔存) 
		long int filesize;			// 檔案大小
		time_t EnterTime;		    // 進入時間 (每次服務更新的時間)
		time_t NowCheckTime;		// 目前時間
		float ratio;				// ratio
		float x;					// delte X 代表調整的變數

		time_t FTP_waitTime;		// FTP等待時間
		time_t Streaming_waitTime;	//  Streaming等待時間
		time_t VOIP_waitTime;		// VOIP等待時間
		
		int FTP_waitCount;			// FTP 等待次數
		int Streaming_waitCount;	// Streaming 等待次數
		int VOIP_waitCount;			// VOIP 等待次數
		
		int FTP_waittotal;			// FTP 等待總次數
		int Streaming_waittotal;	// Streaming 等待總次數
		int VOIP_waittotal;			// VOIP 等待總次數
		
		int FTP_sucessful;			// FTP 成功次數
		int Streaming_sucessful;	// Streaming 成功次數
		int VOIP_sucessful;			// VOIP 成功次數
		
} service_item;

typedef struct Mbandwidth{
    float MAXBW ;						// 網路上可提供最大頻寬總量(k)
    float leftBW ;						// 目前總使用頻寬
    float VOIPBW_min ;					// VOIP		預設基本使用頻寬 64K
    float FTPBW_min ;					// FTP		預設基本使用頻寬 64K ~ 1M
    float STREAMINGBW_min ;				// STREAMING	預設基本使用頻寬 640K ~ 4M
    float Ws;                   		// streaming 掠奪參考之權重
    float Wf;                   		// ftp           掠奪參考之權重
    float ProvideBW_SUB[SERVICE_TYPE];	// 各服務可抓取的頻寬
    int Service_user[SERVICE_TYPE];		// 各服務使用的人數
	int Check_user[SERVICE_TYPE];		// 確定ftp與streaming服務頻寬達1M與4M的人數
    service_item worknode[SERVICE_TNUM];
}Mbandwidth;


float Check_BW(Mbandwidth *Mbandwidth,int index);
float Get_BW(Mbandwidth *Mbandwidth,int index);
float Check_States(Mbandwidth *Mbandwidth,float As, float Af);
/*=================
 para_inital
==================*/
param_inital(Mbandwidth *Mbandwidth)
{
    int i;
    Mbandwidth->MAXBW = MAX_BW;				    // 網路上可提供最大頻寬總量(k)
    Mbandwidth->leftBW = MAX_BW;			    // 目前總使用頻寬
    Mbandwidth->VOIPBW_min = 64.0;				// VOIP		預設基本使用頻寬 64K
    Mbandwidth->FTPBW_min = 64.0;				// FTP		預設基本使用頻寬 64K ~ 1M
    Mbandwidth->STREAMINGBW_min = 640.0;		// STREAMING	預設基本使用頻寬 640K ~ 4M
    Mbandwidth->Ws=0.2;                         // 掠奪參考之權重
    Mbandwidth->Wf=0.8;		                    // 掠奪參考之權重
	
    
    for(i=0;i<SERVICE_TYPE;i++)
    {
        Mbandwidth->ProvideBW_SUB[i]=0.0;
        Mbandwidth->Service_user[i]=0;
		Mbandwidth->Check_user[i]=0;
    }
    
    for(i=0;i<100;i++)
	{
		Mbandwidth->worknode[i].flag = 0;
		Mbandwidth->worknode[i].service = -1;		//	20100308
		Mbandwidth->worknode[i].bandwidth =0;		//	20100308
		Mbandwidth->worknode[i].filesize = 0;		//	20100308
		Mbandwidth->worknode[i].ratio = 0;			//	20100308
		Mbandwidth->worknode[i].x = (float)0.5;
		
		Mbandwidth->worknode[i].FTP_waitCount = 0;			//	20100427
		Mbandwidth->worknode[i].Streaming_waitCount = 0;	//	20100427
		Mbandwidth->worknode[i].VOIP_waitCount = 0;			//	20100427
		
		Mbandwidth->worknode[i].FTP_waittotal = 0;			//	20100504
		Mbandwidth->worknode[i].Streaming_waittotal = 0;	//	20100504
		Mbandwidth->worknode[i].VOIP_waittotal = 0;			//	20100504
		
		Mbandwidth->worknode[i].FTP_sucessful = 0;			//	20100504
		Mbandwidth->worknode[i].Streaming_sucessful = 0;	//	20100504
		Mbandwidth->worknode[i].VOIP_sucessful = 0;			//	20100504
		
		//printf("Mbandwith->MAXBW=%f\n",Mbandwith->MAXBW);
	}
}

/*=================
 Free service 
==================*/
float Free_service(Mbandwidth *Mbandwidth)
{
    static float free_bw;
	static float total_bw;
	//static float Free_BW;
    int i,j;
    double result;
    time_t cur_time;
    
    free_bw=0;
	total_bw=0;
	//Free_BW=0;
    cur_time = time(NULL); 
    for(i=0 ; i <100 ; i ++)
	{
		if(Mbandwidth->worknode[i].flag == 1 && Mbandwidth->worknode[i].service ==0)
        {
            if(rand()%20==0)						  // VOIP 結束關閉
            {
				printf("關閉服務%d\n",i);
                Mbandwidth->worknode[i].flag = 0;     // 服務關閉
                free_bw += Mbandwidth->worknode[i].bandwidth   ; 
                Mbandwidth->worknode[i].bandwidth=0; 
                Mbandwidth->Service_user[Mbandwidth->worknode[i].service] --;
            }
        }
	
        if(Mbandwidth->worknode[i].flag == 1 && Mbandwidth->worknode[i].service !=0)
        {
            //計算時間差(sec) 
            result=difftime(cur_time,Mbandwidth->worknode[i].EnterTime);
            
            //計算未傳輸完成的檔案大小 
            Mbandwidth->worknode[i].filesize -= Mbandwidth->worknode[i].bandwidth*result;
            
            //printf("[%d]flag=%d[%f %f]file=%d\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].bandwidth,result,Mbandwidth->worknode[i].filesize);
            //printf("[%d]difftime=%f\n",i,result);
            if(Mbandwidth->worknode[i].filesize <=0)   // 檔案傳輸完成 
            {
                printf("關閉服務%d\n",i);
                Mbandwidth->worknode[i].flag = 0;      // 服務關閉
                free_bw+=Mbandwidth->worknode[i].bandwidth;  
				Mbandwidth->worknode[i].bandwidth = 0;
                Mbandwidth->Service_user[Mbandwidth->worknode[i].service] --;
            }
        }
        Mbandwidth->worknode[i].EnterTime = cur_time;
    }
	
	if(free_bw>0)
	{
		for(i = 0 ; i <100 ; i++)
		{
			if(Mbandwidth->worknode[i].flag==1)
			{	// 編號   使用狀況旗標  服務類型   此服務之頻寬大小     此服務所配得之檔案大小
				printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].service,Mbandwidth->worknode[i].bandwidth,Mbandwidth->worknode[i].filesize);
			}
		}
	}
	
	/*if(free_bw >0)
	{
		for(i = 0 ; i <100 ; i++)
		{
			if(Mbandwidth->worknode[i].flag==1)
			{	// 編號   使用狀況旗標  服務類型   此服務之頻寬大小     此服務所配得之檔案大小
				printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].service,Mbandwidth->worknode[i].bandwidth,Mbandwidth->worknode[i].filesize);  
				//total_bw+=Mbandwidth->worknode[i].bandwidth;		// 目前全部使用掉的頻寬有多少
				//Free_BW = 8000 - total_bw;
			}
		}
		
		printf("-------------------------------------------------------\n"); 
		//printf("                            total BW  %f   Free_BW=%f\n",total_bw, Free_BW);
		printf("                            total BW  %f   Free_BW=%f\n",8000-Mbandwidth->leftBW-free_bw, Mbandwidth->leftBW+free_bw);
		printf("-------------------------------------------------------\n"); 
	}*/

    printf("可回收頻寬=%f\n",free_bw);
    return free_bw;
}
/*=================
service_redistribute
==================*/
short service_redistribute(Mbandwidth *Mbandwidth,int i)
{
    float check_bw=0.0;
    short tmp;
    float BW_limit[3][3]={{Mbandwidth->VOIPBW_min,0.0,0.0},{Mbandwidth->FTPBW_min,1000.0,0.0},{Mbandwidth->STREAMINGBW_min,4000.0,0.0}};
    short BW_gate[3]={0,1,1};
    //printf("Mbandwith->MAXBW=%f\n",Mbandwith->MAXBW);
    Mbandwidth->leftBW += Free_service(Mbandwidth);  
    if(Mbandwidth->leftBW  >=  BW_limit[Mbandwidth->worknode[i].service][1])		// 判斷是否還有多於頻寬可提供新服務 
	{
        Mbandwidth->leftBW = Mbandwidth->leftBW - (BW_limit[Mbandwidth->worknode[i].service][1]-Mbandwidth->worknode[i].bandwidth);
        Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][1];
        printf("重新分配頻寬\n");
        return 1;
    }
        
}
/*=================
service_redistribute_Avg
==================*/
short service_redistribute_Avg(Mbandwidth *Mbandwidth)
{
	int i;
	float seize_bw=0.0;
    float BW_SEIZE[3]={.0,.0,.0};  // BW_SEIZE[3] = { voip , ftp , stream }
    short tmp;
    float BW_limit[3][3]={{Mbandwidth->VOIPBW_min,0.0,0.0},{Mbandwidth->STREAMINGBW_min,4000.0,0.0},{Mbandwidth->FTPBW_min,1000.0,0.0}};
    short BW_gate[3]={0,1,1};
    
    if(Mbandwidth->leftBW  > 0)		// 判斷是否還有多於頻寬可提供新服務 
	{
         printf("***重新分配\n");
         if(Mbandwidth->Service_user[2] > 0 && Mbandwidth->Service_user[1] >0)
         {
			for(i =0;i<100;i++)
			{
				if( (Mbandwidth->worknode[i].service ==2) && (Mbandwidth->worknode[i].bandwidth <4000) ) // 剩餘頻寬 < 4000 
				{
					Mbandwidth->Check_user[2] ++;	// 篩選出服務小於 4000  的人數
				}
				if( (Mbandwidth->worknode[i].service ==1) && (Mbandwidth->worknode[i].bandwidth <1000) ) // 剩餘頻寬 < 1000 
				{
					Mbandwidth->Check_user[1] ++;	// 篩選出服務小於 1000  的人數
				}
			}
             //BW_SEIZE[2]= Mbandwidth->leftBW * Mbandwidth->Ws / Mbandwidth->Service_user[2];	// streaming
             //BW_SEIZE[1]= Mbandwidth->leftBW * Mbandwidth->Wf / Mbandwidth->Service_user[1];	// ftp
			 BW_SEIZE[2]= Mbandwidth->leftBW * Mbandwidth->Ws / Mbandwidth->Check_user[2];	// streaming
			 BW_SEIZE[1]= Mbandwidth->leftBW * Mbandwidth->Wf / Mbandwidth->Check_user[1];	// ftp
			 
         }
		 else if(Mbandwidth->Service_user[2] > 0)
		 {
			for(i =0;i<100;i++)
			{
				if( (Mbandwidth->worknode[i].service ==2) && (Mbandwidth->worknode[i].bandwidth <4000) ) // 剩餘頻寬 < 4000 
				{
					Mbandwidth->Check_user[2] ++;	// 篩選出服務小於 4000  的人數
				}
			}
			
             BW_SEIZE[2]= Mbandwidth->leftBW * 1.0 / Mbandwidth->Check_user[2];
		 }
         else if( Mbandwidth->Service_user[1] >0)
		 {
			for(i =0;i<100;i++)
			{
				if( (Mbandwidth->worknode[i].service ==1) && (Mbandwidth->worknode[i].bandwidth <1000) ) // 剩餘頻寬 < 1000 
				{
					Mbandwidth->Check_user[1] ++;	// 篩選出服務小於 1000  的人數
				}
			}
			
             BW_SEIZE[1]= Mbandwidth->leftBW * 1.0 / Mbandwidth->Check_user[1];
		 }
         
		 for(i=0 ; i <100 ; i ++)
	     {  
             if(Mbandwidth->worknode[i].flag == 1 && BW_gate[Mbandwidth->worknode[i].service]==1) 
             {
				Mbandwidth->worknode[i].bandwidth +=  BW_SEIZE[Mbandwidth->worknode[i].service];
                seize_bw+=  BW_SEIZE[Mbandwidth->worknode[i].service];
             }
         }      
         Mbandwidth->leftBW-= seize_bw;                                                
         //Mbandwidth.Service_user[Mbandwidth.worknode[i].service]
        /*依權重Wf,Ws來分配頻寬,Streaming must check it's PSNR range*/
        return 1;
    }
}
/*=================
service_init
==================*/
short service_init(Mbandwidth *Mbandwidth,int i)
{

	time_t cur_time;
    float check_bw=0.0;
    short tmp;
						//  {64.0 ,0.0 ,0.0 }               ,{64.0 ,1000.0 ,0.0 }              ,{640.0 ,4000.0 ,0.0 }
    float BW_limit[3][3]={{Mbandwidth->VOIPBW_min,0.0,0.0},{Mbandwidth->FTPBW_min,1000.0,0.0},{Mbandwidth->STREAMINGBW_min,4000.0,0.0}};
    short BW_gate[3]={0,1,1};  // ftp , streaming
    //printf("Mbandwith->MAXBW=%f\n",Mbandwith->MAXBW);
   	
	Mbandwidth->Service_user[Mbandwidth->worknode[i].service] ++;			//  計數各服務的人數
    Mbandwidth->leftBW += Free_service(Mbandwidth);                   		//  計算是否有傳輸完畢並回收頻寬 
    
	/**************service_redistribute_Avg *******************/
	// service_redistribute_Avg(Mbandwidth);     // 釋放後必須馬上分給大家用 20100418
	
	if(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0])	// 判斷是否還有多於頻寬可提供新服務 
	{
        if(BW_gate[Mbandwidth->worknode[i].service]==1)
        {
            //tmp=(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][1])?1:0;  // 剩餘頻寬 > 1M或4M -> tmp=1 ; 否則 tmp=0
            //printf("=>%d %f %f\n",tmp,Mbandwidth->leftBW,BW_limit[Mbandwidth->worknode[i].service][1]);
		    //Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][tmp];	// tmp=1 -> 使用1M或4M  ; tmp=0 -> 使用64K或640K
			
			if(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][1]) // 剩餘頻寬 > 1M或4M 
			{
				tmp=1;
				Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][tmp];  // 給 1M或4M 
			}
			else if( (Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0]) && (BW_limit[Mbandwidth->worknode[i].service][1]> Mbandwidth->leftBW) ) // 剩餘頻寬 > 64K或640K 且 最大頻寬 > 剩餘頻寬
			{
				Mbandwidth->worknode[i].bandwidth = Mbandwidth->leftBW; // 給剩餘頻寬
			}
		}else
		    Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][0];	// 此為VOIP
		
		Mbandwidth->worknode[i].flag = 1;
		if(Mbandwidth->worknode[i].service==1)			// 此為 FTP 服務                                  
            //Mbandwidth->worknode[i].filesize = 200*((rand()%10)*10) + (rand()%10)+400 ;	// FTP 檔案大小			// 20100514
			Mbandwidth->worknode[i].filesize = filesize1[i];							// FTP 檔案大小
        else if(Mbandwidth->worknode[i].service==2)		// 此為 STREAMING 服務
        	//Mbandwidth->worknode[i].filesize = 400*((rand()%10)*10) + (rand()%10)+400 ; 	// STREAMING 檔案大小	// 20100514
			Mbandwidth->worknode[i].filesize = filesize1[i]; 							// STREAMING 檔案大小
		else                                         	// 此為 VOIP 服務 
		    //Mbandwidth->worknode[i].filesize = -1;							// VOIP 不須給檔案		// 20100514
		    Mbandwidth->worknode[i].filesize = filesize1[i];							// VOIP 不須給檔案
			
		printf("[%d]初始化檔案大小=%ld \n",i,Mbandwidth->worknode[i].filesize);
		
		Mbandwidth->worknode[i].EnterTime = time(NULL);									//進入時間設定(供查詢總傳輸量用) 
		//printf("%ld\n",Mbandwidth->worknode[i].EnterTime);
		printf("%s",ctime(&Mbandwidth->worknode[i].EnterTime));
		
		Mbandwidth->leftBW = Mbandwidth->leftBW - Mbandwidth->worknode[i].bandwidth;	// "新的" 剩餘頻寬 = 剩餘頻寬- 該服務所配得頻寬
		printf("剩餘頻寬大小=%f\n",Mbandwidth->leftBW);
		
        if(Mbandwidth->leftBW > Mbandwidth->MAXBW) 
            system("pause") ;
        return 1;
	}
	else   // 原有頻寬不足,去向現在使用的service要頻寬					
	{
        printf("剩餘頻寬大小=%f\n",Mbandwidth->leftBW); 
        printf("Check 現有頻寬大小\n");
        check_bw = Check_BW(Mbandwidth,i); //  check Optimizatal bandwidth
        printf("最佳可取出頻寬大小=%f\n",check_bw);
        
        //目前新加入先以最小頻寬為設定 
        if(check_bw + Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0] )
		{
		    //Get_BW(Mbandwidth,i);//抓取頻寬 ,設定各頻寬抓取後的新值,回傳抓到的頻寬 
		    //==================
		    Mbandwidth->worknode[i].bandwidth =Get_BW(Mbandwidth,i);	// 抓取頻寬 ,設定各頻寬抓取後的新值,回傳抓到的頻寬
	       	Mbandwidth->worknode[i].flag = 1;
		    // if(Mbandwidth->worknode[i].service==1)  	// 此為 FTP 服務                                   
                // Mbandwidth->worknode[i].filesize = 100*((rand()%10)*10) + (rand()%10)+300 ; // FTP 檔案大小
            // else if(Mbandwidth->worknode[i].service==2)	// 此為 STREAMING 服務
        	    // Mbandwidth->worknode[i].filesize = 300*((rand()%10)*10) + (rand()%10)+300 ; // STREAMING 檔案大小
		    // else                                 		// VOIP不給檔案大小 
		        // Mbandwidth->worknode[i].filesize = -1;										// VOIP 不須給檔案
				
			if(Mbandwidth->worknode[i].service==1)			// 此為 FTP 服務                                  
				//Mbandwidth->worknode[i].filesize = 200*((rand()%10)*10) + (rand()%10)+400 ;	// FTP 檔案大小			// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i];							// FTP 檔案大小
			else if(Mbandwidth->worknode[i].service==2)		// 此為 STREAMING 服務
				//Mbandwidth->worknode[i].filesize = 400*((rand()%10)*10) + (rand()%10)+400 ; 	// STREAMING 檔案大小	// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i]; 							// STREAMING 檔案大小
			else                                         	// 此為 VOIP 服務 
				//Mbandwidth->worknode[i].filesize = -1;							// VOIP 不須給檔案		// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i];							// VOIP 不須給檔案
			
		    printf("[%d]初始化檔案大小=%ld \n",i,Mbandwidth->worknode[i].filesize);
		
		    Mbandwidth->worknode[i].EnterTime = time(NULL);                 //進入時間設定(供查詢總傳輸量用) 
		    //printf("%ld\n",Mbandwidth->worknode[i].EnterTime);
		    printf("%s",ctime(&Mbandwidth->worknode[i].EnterTime));
		
		    printf("剩餘頻寬大小=%f\n",Mbandwidth->leftBW);
		    //==================
		    printf("抓取其它服務頻寬,來新增服務\n"); 
		    return 1;
        }
        else
        {
			cur_time = time(NULL); // 紀錄服務失敗當時的時間
			
			printf("抽取頻寬不足以提供新服務 (服務類別為%d)  (服務頻寬所需之大小為%f) \n",Mbandwidth->worknode[i].service,BW_limit[Mbandwidth->worknode[i].service][0]);
            printf("頻寬不足,無法新增服務.等待一秒\n");
			
			if(Mbandwidth->worknode[i].service==1)  			// 此為 FTP 服務
			{
				Mbandwidth->worknode[i].FTP_waitTime = cur_time;
				Mbandwidth->worknode[i].FTP_waitCount++;
				if(Mbandwidth->worknode[i].FTP_waitCount == 2)			// 真正等待一秒
				{
					Mbandwidth->worknode[i].FTP_sucessful = 1;			// FTP 失敗次數記錄旗標
				}
				printf("FTP失敗時間 %s",ctime(&Mbandwidth->worknode[i].FTP_waitTime));
				printf("FTP服務失敗次數 %d \n",Mbandwidth->worknode[i].FTP_waitCount);
			}
			else if(Mbandwidth->worknode[i].service==2)			// 此為 STREAMING 服務
			{	
				Mbandwidth->worknode[i].Streaming_waitTime = cur_time;	
				Mbandwidth->worknode[i].Streaming_waitCount++;
				if(Mbandwidth->worknode[i].Streaming_waitCount == 2)	// 真正等待一秒
				{
					Mbandwidth->worknode[i].Streaming_sucessful = 1;	// Streaming 失敗次數記錄旗標
				}
				printf("STREAMING失敗時間 %s",ctime(&Mbandwidth->worknode[i].Streaming_waitTime));
				printf("STREAMING服務失敗次數 %d \n",Mbandwidth->worknode[i].Streaming_waitCount);
			}
			else												// 此為 VOIP 服務
			{
				Mbandwidth->worknode[i].VOIP_waitTime = cur_time;
				Mbandwidth->worknode[i].VOIP_waitCount++;
				if(Mbandwidth->worknode[i].VOIP_waitCount == 2)			// 真正等待一秒
				{
					Mbandwidth->worknode[i].VOIP_sucessful = 1;			// VOIP 失敗次數記錄旗標
				}
				printf("VOIP失敗時間 %s",ctime(&Mbandwidth->worknode[i].VOIP_waitTime));
				printf("VOIP服務失敗次數 %d \n",Mbandwidth->worknode[i].VOIP_waitCount);
			}
			
			printf("\n");
			Mbandwidth->worknode[i].FTP_waittotal = Mbandwidth->worknode[i].FTP_waitCount; 
			Mbandwidth->worknode[i].Streaming_waittotal = Mbandwidth->worknode[i].Streaming_waitCount; 
			Mbandwidth->worknode[i].VOIP_waittotal = Mbandwidth->worknode[i].VOIP_waitCount;
			
			printf("FTP服務計數總失敗次數 %d \n",Mbandwidth->worknode[i].FTP_waitCount);
			printf("STREAMING服務計數總失敗次數 %d \n",Mbandwidth->worknode[i].Streaming_waitCount);
			printf("VOIP服務計數總失敗次數 %d \n",Mbandwidth->worknode[i].VOIP_waitCount);
			
			printf("\n");
			printf("FTP服務總失敗次數 %d \n",Mbandwidth->worknode[i].FTP_waittotal);
			printf("STREAMING服務總失敗次數 %d \n",Mbandwidth->worknode[i].Streaming_waittotal);
			printf("VOIP服務總失敗次數 %d \n",Mbandwidth->worknode[i].VOIP_waittotal);
			
            return 0;
        }
        //system("pause");
    }
}

main()
{
    int s;						// 判斷服務亂數
    int i,j,count ;
    float total_bw,voip_TBW=0.0;
	
	static int countFlag=0;		// 計數目前所有服務的總人數
	static int servicecount=0;	// 服務次數計數
	
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	char buffer[80],filename[20],filename1[20],filename2[20],filename3[20],filename4[20];
    
	struct tm * timeinfo;
    
	Mbandwidth Mbandwidth;				// 結構變數
	   
    srand((unsigned)time(NULL));		// 取亂數種子
	
    param_inital(&Mbandwidth);
    //printf("Mbandwith.MAXBW=%f\n",Mbandwith.MAXBW);
    
	for(i = 0 ; i <100 ; i++)
    {	
		sprintf(filename3,"UseBw1.txt");
		fp4=fopen(filename3,"a+");
		fprintf(fp4,"第一階段分配頻寬\n");
		fprintf(fp4,"編號\t使用狀況旗標\t服務類型\t服務之頻寬\t檔案大小\n");
		
		sprintf(filename4,"Service.txt");
		fp5=fopen(filename4,"a+");
		
        // s = rand()%3;						// 範圍 0 ~ 2 
		s = rand1[i];
		
		//printf("Mbandwith.MAXBW=%d\n",Mbandwith.MAXBW);
		Mbandwidth.worknode[i].service = s;
		while(1)
		{
            total_bw=0.0;
            printf("******************************************************\n");
            for(j = 0 ; j <i ; j++)
            {
                if(Mbandwidth.worknode[j].flag==1)
				{
					countFlag++;
													// 編號   使用狀況旗標  服務類型   此服務之頻寬大小     此服務所配得之檔案大小
                    printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);  
					// fprintf(fp4,"[%d]service=%d\tbandwidth=%f\n",j,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth);	// 20100506
					// fprintf(fp4,"[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);	// 20100506s
					fprintf(fp4,"[%d]\t%d\t%d\t%f\t%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);
					total_bw+=Mbandwidth.worknode[j].bandwidth;		// 目前全部使用掉的頻寬有多少
                }
            }
			servicecount++;
			fprintf(fp4,"******************************************************\n");
			fprintf(fp4,"服務次數\t\t服務數量\n");
			fprintf(fp4,"%d\t\t%d\n",servicecount,countFlag);
			fprintf(fp4,"\n");
			
			fprintf(fp5,"******************************************************\n");
			fprintf(fp5,"服務次數\t\t服務數量\n");
			fprintf(fp5,"%d\t\t%d\n",servicecount,countFlag);
			fprintf(fp5,"\n");
			
			countFlag = 0;
			
			fclose(fp4);
			fclose(fp5);
            printf("-------------------------------------------------------\n"); 
            printf("                            total BW  %f   Free_BW=%f\n",total_bw,Mbandwidth.leftBW );
            printf("-------------------------------------------------------\n"); 
		    printf("加入 Random Number [%d] is %d\n",i,s);
		    if(	service_init(&Mbandwidth,i)>0)
                break;
            else
                sleep(1000);
        }
        
        //=====報表列印====== 
        timeinfo = localtime ( &Mbandwidth.worknode[0].EnterTime );
        		 
		for(j = 0 ; j <100 ; j++)
        {
            sprintf(filename,"S%05d.txt",j+1);
            if(j==i)
                strftime (buffer,80,"%H:%M:%S",localtime ( &Mbandwidth.worknode[j].EnterTime ));
            else
                strftime (buffer,80,"%H:%M:%S",timeinfo);
            
            fp1=fopen(filename,"a+");
            fprintf(fp1,"%d\t%d\t%s\t%f\t%ld\n",j+1,Mbandwidth.worknode[j].service,buffer,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);
			fclose(fp1);
        }
       
		//====================
		//sleep(1000);
		printf("\n");
		//sleep((rand()%2)*1000);            //服務的間格時間 !~2
    }
	
	//計算除了voip的頻寬 
	/*for(i = 0 ; i <100 ; i++)
    {
        if(Mbandwidth.worknode[i].service==0)
            voip_TBW+=Mbandwidth.VOIPBW_min;
            
    }*/
	//所有服務都進入了,跑完直到回收所有頻寬 

	while(1) // 確定大家ㄉ服務都結束後才可以跳出迴圈
	{
        count=0; // 確認100人服務內是否還有存活(使用中)  flag-=1
		
		Mbandwidth.leftBW += Free_service(&Mbandwidth);
		
		/**************service_redistribute_Avg *******************/
		service_redistribute_Avg(&Mbandwidth);
		
		sprintf(filename3,"UseBw1.txt");
		fp4=fopen(filename3,"a+");
		fprintf(fp4,"第二階段分配頻寬\n");
		fprintf(fp4,"編號\t使用狀況旗標\t服務類型\t服務之頻寬\t檔案大小\n");
		
		sprintf(filename4,"Service.txt");
		fp5=fopen(filename4,"a+");
				
        for(j = 0 ; j <100 ; j++)
        {			
            if(Mbandwidth.worknode[j].flag==1)
            {
                //if(Mbandwidth.worknode[j].service!=0)
                //{
                    count++;
					countFlag++;
                //}
				printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize); 
                // fprintf(fp4,"[%d]service=%d\tbandwidth=%f\n",j,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth);	// 20100506
				// fprintf(fp4,"[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);	// 20100506
				fprintf(fp4,"[%d]\t%d\t%d\t%f\t%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);
				//total_bw+=Mbandwidth.worknode[j].bandwidth;
            }
            //=====報表列印====== 
            timeinfo = localtime ( &Mbandwidth.worknode[0].EnterTime );
			
            sprintf(filename,"S%05d.txt",j+1);
            strftime (buffer,80,"%H:%M:%S",timeinfo);
            
            fp1=fopen(filename,"a+");
            fprintf(fp1,"%d\t%d\t%s\t%f\t%ld\n",j+1,Mbandwidth.worknode[j].service,buffer,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);        
            fclose(fp1);
            //====================
        }
		servicecount++;
        fprintf(fp4,"******************************************************\n");
		fprintf(fp4,"服務次數\t\t服務數量\n");
		fprintf(fp4,"%d\t\t%d\n",servicecount,countFlag);
		fprintf(fp4,"\n");
		
		fprintf(fp5,"******************************************************\n");
		fprintf(fp5,"服務次數\t\t服務數量\n");
		fprintf(fp5,"%d\t\t%d\n",servicecount,countFlag);
		fprintf(fp5,"\n");
		
		countFlag = 0;
		
		fclose(fp4);
		fclose(fp5);
	    //Mbandwidth.leftBW += Free_service(&Mbandwidth);
	    //if(Mbandwidth.leftBW + voip_TBW > Mbandwidth.MAXBW-1.0)
	    //    break;
	    printf("count=%d\n",count);
	    if(count==0)
	           break;
	    sleep(1000);
    }
	
	for(j = 0 ; j <100 ; j++)
	{   
			sprintf(filename1,"wait.txt");
            fp2=fopen(filename1,"a+");
            fprintf(fp2,"%d\t%d\t%d\n",Mbandwidth.worknode[j].FTP_waitCount,Mbandwidth.worknode[j].Streaming_waitCount,Mbandwidth.worknode[j].VOIP_waitCount);
			fclose(fp2);
	}
	for(j = 0 ; j <100 ; j++)
	{   
			sprintf(filename2,"sucessful.txt");
            fp3=fopen(filename2,"a+");
            fprintf(fp3,"%d\t%d\t%d\n",Mbandwidth.worknode[j].FTP_sucessful,Mbandwidth.worknode[j].Streaming_sucessful,Mbandwidth.worknode[j].VOIP_sucessful);
			fclose(fp3);
    }
	
    system("pause");
}

float Check_States(Mbandwidth *Mbandwidth,float As, float Af) // service : FTP or Streaming
{
	static float ProvideBW;
	ProvideBW=0.0;
	float releaseBW;
	releaseBW=0.0;
	float BW_info[3]={Mbandwidth->VOIPBW_min,Mbandwidth->FTPBW_min,Mbandwidth->STREAMINGBW_min}; // { 64K , 64K , 640K }
    short BW_gate[3]={0,1,1};
   	float A_ratio[3]={0.0,Af,As};
	int i=0;
	
	for(i=0;i<100;i++)
	{
		//if(BW_gate[Mbandwidth->worknode[i].service]==1 && Mbandwidth->worknode[i].flag == 1 &&
		//	Mbandwidth->worknode[i].bandwidth > BW_info[Mbandwidth->worknode[i].service])
		if(BW_gate[Mbandwidth->worknode[i].service]==1 && Mbandwidth->worknode[i].flag == 1 &&
			Mbandwidth->worknode[i].bandwidth > BW_info[Mbandwidth->worknode[i].service] && A_ratio[Mbandwidth->worknode[i].service] != 0.0)
		{
			releaseBW = Mbandwidth->worknode[i].bandwidth * ( 1 - ( Mbandwidth->worknode[i].ratio +  ( 1 - Mbandwidth->worknode[i].ratio) * Mbandwidth->worknode[i].x ) )*A_ratio[Mbandwidth->worknode[i].service];
			if(Mbandwidth->worknode[i].bandwidth - releaseBW >  BW_info[Mbandwidth->worknode[i].service])//可以抓取頻寬 
			{
				Mbandwidth->worknode[i].release_bw=releaseBW;	 // 將所抓取 (掠奪) 的頻寬 轉存(暫存) 至結構內的可釋放出的BW
				ProvideBW+=releaseBW;
				//Mbandwidth->worknode[i].bandwidth -= releaseBW;
			}else
				printf("[NOTED]調整後太小不釋放空間\n");
		}
	}
	
	return ProvideBW;//最後釋放空間大小 
}

float Check_BW(Mbandwidth *Mbandwidth,int index)				// 查看其他人的 FTP BW 是否更提供給我使用
{
    static float ProvideBW;
    ProvideBW=0.0;
    int i=0;
    float BW_info[3]={Mbandwidth->VOIPBW_min,Mbandwidth->FTPBW_min,Mbandwidth->STREAMINGBW_min}; // { 64K , 64K , 640K }
    short BW_gate[3]={0,1,1};
    for(i=0;i<SERVICE_TYPE;i++)
        Mbandwidth->ProvideBW_SUB[i]=0.0;
    
    //check 最佳化大小 
	for(i=0 ; i <100 ; i ++)
	{
        Mbandwidth->worknode[i].release_bw=0.0;	//歸0,等下check真實抓取,可先存下來 
        //頻寬抓取條件 :1.只有ftp,streaming 2.要服務還存在 3.要頻寬 > 該服務最小頻寬 
        if(BW_gate[Mbandwidth->worknode[i].service]==1 && Mbandwidth->worknode[i].flag == 1 &&
           Mbandwidth->worknode[i].bandwidth > BW_info[Mbandwidth->worknode[i].service])
        {
            Mbandwidth->worknode[i].ratio =  BW_info[Mbandwidth->worknode[i].service] / Mbandwidth->worknode[i].bandwidth ;
            Mbandwidth->ProvideBW_SUB[Mbandwidth->worknode[i].service] += Mbandwidth->worknode[i].bandwidth * (1-(Mbandwidth->worknode[i].ratio +  (1-Mbandwidth->worknode[i].ratio) * Mbandwidth->worknode[i].x ));
            Mbandwidth->worknode[i].release_bw = Mbandwidth->worknode[i].bandwidth * (1-(Mbandwidth->worknode[i].ratio +  (1-Mbandwidth->worknode[i].ratio) * Mbandwidth->worknode[i].x ));	
			//printf("[%d][s%d] provide %f\t",i,Mbandwidth->worknode[i].service,Mbandwidth->ProvideBW_SUB[Mbandwidth->worknode[i].service]);
        }
	}
	// Mbandwidth->ProvideBW_SUB[0] : VOIP 可抓取的BW  ;       20100418
	// Mbandwidth->ProvideBW_SUB[1] : FTP可抓取的BW  ;          20100418
	//Mbandwidth->ProvideBW_SUB[2] : Streaming 可抓取的BW   20100418
	
	//ProvideBW=Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2];
	printf("最大可抓取=>%f (%f)(%f)(%f)\n",Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2],Mbandwidth->ProvideBW_SUB[0],Mbandwidth->ProvideBW_SUB[1],Mbandwidth->ProvideBW_SUB[2]);

    //當最大可抓取 < 該服務最小頻寬時-剩餘最小頻寬 失敗 
    if(Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2] 
       < BW_info[Mbandwidth->worknode[index].service]-Mbandwidth->leftBW)
        return 0.0; 
        
	//check 真實抓取 
	float Avoip, As=0.0, Af=0.0;
	float A_ratio[3]={0.0,Af,As};
    float releaseBW;
	releaseBW=0.0;
	
	if(Mbandwidth->ProvideBW_SUB[1]==0)//+1.0因為怕四捨五入有時會小時最小頻寬一點點     	// FTP 服務人數等於0
	{
		As=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[2];
		
		printf("需求頻寬=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		ProvideBW = Check_States(Mbandwidth,As,Af);
	}
	else if(Mbandwidth->ProvideBW_SUB[2]==0)  								// streaing 服務人數等於0
	{
		Af=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[1];
		
		printf("需求頻寬=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		ProvideBW = Check_States(Mbandwidth,As,Af);
	}
	else
	{
		Af = ( Mbandwidth->Wf *(BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[1];	// FTP 調整比例
		As = ( Mbandwidth->Ws *(BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[2];	// Streaming 調整比例
		
		//printf("需求頻寬=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		//ProvideBW = Check_States(Mbandwidth,As,Af);
		
		//static float GiveAS, GiveAf;
		//GiveAS = 0; 
		//GiveAf = 0;
		
		if( As>=1 )
		{		
			As=0.0;
			//GiveAS = Mbandwidth->ProvideBW_SUB[2];	// Streaming 可提供之頻寬
			Af=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/-Mbandwidth->ProvideBW_SUB[2]) +1.0)
				/ Mbandwidth->ProvideBW_SUB[1];
		
			printf("Check_States(Mbandwidth,As,Af) = %f \n Mbandwidth->ProvideBW_SUB[2] =%f\n",Check_States(Mbandwidth,As,Af),Mbandwidth->ProvideBW_SUB[2]);
			
			ProvideBW = Check_States(Mbandwidth,As,Af)+Mbandwidth->ProvideBW_SUB[2];
		}
		else if( Af >=1 )
		{
			Af=0.0;
			//GiveAf = Mbandwidth->ProvideBW_SUB[1];	// FTP 可提供之頻寬
			As=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/-Mbandwidth->ProvideBW_SUB[1]) +1.0) 
			/ Mbandwidth->ProvideBW_SUB[2];
			
			printf("Check_States(Mbandwidth,As,Af) = %f\n Mbandwidth->ProvideBW_SUB[1]=%f\n",Check_States(Mbandwidth,As,Af),Mbandwidth->ProvideBW_SUB[1]);
			
			ProvideBW = Check_States(Mbandwidth,As,Af)+Mbandwidth->ProvideBW_SUB[1];
		}
		else //if( As < 1 &&  Af < 1 )
		{
			printf("需求頻寬=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
			ProvideBW = Check_States(Mbandwidth,As,Af);
		}
	}
	
	
	return ProvideBW;//最後釋放空間大小 
}

float Get_BW(Mbandwidth *Mbandwidth,int index)						// 真實掠奪的BW
{
    int i;
    static float ProvideBW;
    ProvideBW=0.0;
    for(i=0;i<100;i++)
        if(Mbandwidth->worknode[i].release_bw>0.0)
        {
            ProvideBW+=Mbandwidth->worknode[i].release_bw;
            Mbandwidth->worknode[i].bandwidth-=Mbandwidth->worknode[i].release_bw;
        }
    ProvideBW+=  Mbandwidth->leftBW;   
    Mbandwidth->leftBW-=Mbandwidth->leftBW;
    printf("Get_BW()=%f\n",ProvideBW);
	
    return ProvideBW;
}
