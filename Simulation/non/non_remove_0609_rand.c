#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#define SERVICE_TYPE 3             	// ���ѪA�Ȫ�����  0 :VOIP  1:FTP  2:Streaming
#define SERVICE_TNUM 100           	// �̤j�A�ȼ� 
#define MAX_BW 10000                // �̤j�W�e 

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
		int flag;					// 0:�N�����}�άO�L�H�ϥ� , 1:�N���H�ϥΤ�
		int service;				// �A��
		float bandwidth;			// �C���A�Ȥ��C�ӨϥΪ̩Ҧ��Ϊ��W�e	= Breal
		float release_bw;           // �n���񪺪Ŷ��j�p(���s) 
		long int filesize;			// �ɮפj�p
		time_t EnterTime;		    // �i�J�ɶ� (�C���A�ȧ�s���ɶ�)
		time_t NowCheckTime;		// �ثe�ɶ�
		float ratio;				// ratio
		float x;					// delte X �N��վ㪺�ܼ�

		time_t FTP_waitTime;		// FTP���ݮɶ�
		time_t Streaming_waitTime;	//  Streaming���ݮɶ�
		time_t VOIP_waitTime;		// VOIP���ݮɶ�
		
		int FTP_waitCount;			// FTP ���ݦ���
		int Streaming_waitCount;	// Streaming ���ݦ���
		int VOIP_waitCount;			// VOIP ���ݦ���
		
		int FTP_waittotal;			// FTP �����`����
		int Streaming_waittotal;	// Streaming �����`����
		int VOIP_waittotal;			// VOIP �����`����
		
		int FTP_sucessful;			// FTP ���\����
		int Streaming_sucessful;	// Streaming ���\����
		int VOIP_sucessful;			// VOIP ���\����
		
} service_item;

typedef struct Mbandwidth{
    float MAXBW ;						// �����W�i���ѳ̤j�W�e�`�q(k)
    float leftBW ;						// �ثe�`�ϥ��W�e
    float VOIPBW_min ;					// VOIP		�w�]�򥻨ϥ��W�e 64K
    float FTPBW_min ;					// FTP		�w�]�򥻨ϥ��W�e 64K ~ 1M
    float STREAMINGBW_min ;				// STREAMING	�w�]�򥻨ϥ��W�e 640K ~ 4M
    float Ws;                   		// streaming ���ܰѦҤ��v��
    float Wf;                   		// ftp           ���ܰѦҤ��v��
    float ProvideBW_SUB[SERVICE_TYPE];	// �U�A�ȥi������W�e
    int Service_user[SERVICE_TYPE];		// �U�A�ȨϥΪ��H��
	int Check_user[SERVICE_TYPE];		// �T�wftp�Pstreaming�A���W�e�F1M�P4M���H��
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
    Mbandwidth->MAXBW = MAX_BW;				    // �����W�i���ѳ̤j�W�e�`�q(k)
    Mbandwidth->leftBW = MAX_BW;			    // �ثe�`�ϥ��W�e
    Mbandwidth->VOIPBW_min = 64.0;				// VOIP		�w�]�򥻨ϥ��W�e 64K
    Mbandwidth->FTPBW_min = 64.0;				// FTP		�w�]�򥻨ϥ��W�e 64K ~ 1M
    Mbandwidth->STREAMINGBW_min = 640.0;		// STREAMING	�w�]�򥻨ϥ��W�e 640K ~ 4M
    Mbandwidth->Ws=0.2;                         // ���ܰѦҤ��v��
    Mbandwidth->Wf=0.8;		                    // ���ܰѦҤ��v��
	
    
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
            if(rand()%20==0)						  // VOIP ��������
            {
				printf("�����A��%d\n",i);
                Mbandwidth->worknode[i].flag = 0;     // �A������
                free_bw += Mbandwidth->worknode[i].bandwidth   ; 
                Mbandwidth->worknode[i].bandwidth=0; 
                Mbandwidth->Service_user[Mbandwidth->worknode[i].service] --;
            }
        }
	
        if(Mbandwidth->worknode[i].flag == 1 && Mbandwidth->worknode[i].service !=0)
        {
            //�p��ɶ��t(sec) 
            result=difftime(cur_time,Mbandwidth->worknode[i].EnterTime);
            
            //�p�⥼�ǿ駹�����ɮפj�p 
            Mbandwidth->worknode[i].filesize -= Mbandwidth->worknode[i].bandwidth*result;
            
            //printf("[%d]flag=%d[%f %f]file=%d\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].bandwidth,result,Mbandwidth->worknode[i].filesize);
            //printf("[%d]difftime=%f\n",i,result);
            if(Mbandwidth->worknode[i].filesize <=0)   // �ɮ׶ǿ駹�� 
            {
                printf("�����A��%d\n",i);
                Mbandwidth->worknode[i].flag = 0;      // �A������
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
			{	// �s��   �ϥΪ��p�X��  �A������   ���A�Ȥ��W�e�j�p     ���A�ȩҰt�o���ɮפj�p
				printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].service,Mbandwidth->worknode[i].bandwidth,Mbandwidth->worknode[i].filesize);
			}
		}
	}
	
	/*if(free_bw >0)
	{
		for(i = 0 ; i <100 ; i++)
		{
			if(Mbandwidth->worknode[i].flag==1)
			{	// �s��   �ϥΪ��p�X��  �A������   ���A�Ȥ��W�e�j�p     ���A�ȩҰt�o���ɮפj�p
				printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",i,Mbandwidth->worknode[i].flag,Mbandwidth->worknode[i].service,Mbandwidth->worknode[i].bandwidth,Mbandwidth->worknode[i].filesize);  
				//total_bw+=Mbandwidth->worknode[i].bandwidth;		// �ثe�����ϥα����W�e���h��
				//Free_BW = 8000 - total_bw;
			}
		}
		
		printf("-------------------------------------------------------\n"); 
		//printf("                            total BW  %f   Free_BW=%f\n",total_bw, Free_BW);
		printf("                            total BW  %f   Free_BW=%f\n",8000-Mbandwidth->leftBW-free_bw, Mbandwidth->leftBW+free_bw);
		printf("-------------------------------------------------------\n"); 
	}*/

    printf("�i�^���W�e=%f\n",free_bw);
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
    if(Mbandwidth->leftBW  >=  BW_limit[Mbandwidth->worknode[i].service][1])		// �P�_�O�_�٦��h���W�e�i���ѷs�A�� 
	{
        Mbandwidth->leftBW = Mbandwidth->leftBW - (BW_limit[Mbandwidth->worknode[i].service][1]-Mbandwidth->worknode[i].bandwidth);
        Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][1];
        printf("���s���t�W�e\n");
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
    
    if(Mbandwidth->leftBW  > 0)		// �P�_�O�_�٦��h���W�e�i���ѷs�A�� 
	{
         printf("***���s���t\n");
         if(Mbandwidth->Service_user[2] > 0 && Mbandwidth->Service_user[1] >0)
         {
			for(i =0;i<100;i++)
			{
				if( (Mbandwidth->worknode[i].service ==2) && (Mbandwidth->worknode[i].bandwidth <4000) ) // �Ѿl�W�e < 4000 
				{
					Mbandwidth->Check_user[2] ++;	// �z��X�A�Ȥp�� 4000  ���H��
				}
				if( (Mbandwidth->worknode[i].service ==1) && (Mbandwidth->worknode[i].bandwidth <1000) ) // �Ѿl�W�e < 1000 
				{
					Mbandwidth->Check_user[1] ++;	// �z��X�A�Ȥp�� 1000  ���H��
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
				if( (Mbandwidth->worknode[i].service ==2) && (Mbandwidth->worknode[i].bandwidth <4000) ) // �Ѿl�W�e < 4000 
				{
					Mbandwidth->Check_user[2] ++;	// �z��X�A�Ȥp�� 4000  ���H��
				}
			}
			
             BW_SEIZE[2]= Mbandwidth->leftBW * 1.0 / Mbandwidth->Check_user[2];
		 }
         else if( Mbandwidth->Service_user[1] >0)
		 {
			for(i =0;i<100;i++)
			{
				if( (Mbandwidth->worknode[i].service ==1) && (Mbandwidth->worknode[i].bandwidth <1000) ) // �Ѿl�W�e < 1000 
				{
					Mbandwidth->Check_user[1] ++;	// �z��X�A�Ȥp�� 1000  ���H��
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
        /*���v��Wf,Ws�Ӥ��t�W�e,Streaming must check it's PSNR range*/
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
   	
	Mbandwidth->Service_user[Mbandwidth->worknode[i].service] ++;			//  �p�ƦU�A�Ȫ��H��
    Mbandwidth->leftBW += Free_service(Mbandwidth);                   		//  �p��O�_���ǿ駹���æ^���W�e 
    
	/**************service_redistribute_Avg *******************/
	// service_redistribute_Avg(Mbandwidth);     // ����ᥲ�����W�����j�a�� 20100418
	
	if(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0])	// �P�_�O�_�٦��h���W�e�i���ѷs�A�� 
	{
        if(BW_gate[Mbandwidth->worknode[i].service]==1)
        {
            //tmp=(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][1])?1:0;  // �Ѿl�W�e > 1M��4M -> tmp=1 ; �_�h tmp=0
            //printf("=>%d %f %f\n",tmp,Mbandwidth->leftBW,BW_limit[Mbandwidth->worknode[i].service][1]);
		    //Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][tmp];	// tmp=1 -> �ϥ�1M��4M  ; tmp=0 -> �ϥ�64K��640K
			
			if(Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][1]) // �Ѿl�W�e > 1M��4M 
			{
				tmp=1;
				Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][tmp];  // �� 1M��4M 
			}
			else if( (Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0]) && (BW_limit[Mbandwidth->worknode[i].service][1]> Mbandwidth->leftBW) ) // �Ѿl�W�e > 64K��640K �B �̤j�W�e > �Ѿl�W�e
			{
				Mbandwidth->worknode[i].bandwidth = Mbandwidth->leftBW; // ���Ѿl�W�e
			}
		}else
		    Mbandwidth->worknode[i].bandwidth = BW_limit[Mbandwidth->worknode[i].service][0];	// ����VOIP
		
		Mbandwidth->worknode[i].flag = 1;
		if(Mbandwidth->worknode[i].service==1)			// ���� FTP �A��                                  
            //Mbandwidth->worknode[i].filesize = 200*((rand()%10)*10) + (rand()%10)+400 ;	// FTP �ɮפj�p			// 20100514
			Mbandwidth->worknode[i].filesize = filesize1[i];							// FTP �ɮפj�p
        else if(Mbandwidth->worknode[i].service==2)		// ���� STREAMING �A��
        	//Mbandwidth->worknode[i].filesize = 400*((rand()%10)*10) + (rand()%10)+400 ; 	// STREAMING �ɮפj�p	// 20100514
			Mbandwidth->worknode[i].filesize = filesize1[i]; 							// STREAMING �ɮפj�p
		else                                         	// ���� VOIP �A�� 
		    //Mbandwidth->worknode[i].filesize = -1;							// VOIP �������ɮ�		// 20100514
		    Mbandwidth->worknode[i].filesize = filesize1[i];							// VOIP �������ɮ�
			
		printf("[%d]��l���ɮפj�p=%ld \n",i,Mbandwidth->worknode[i].filesize);
		
		Mbandwidth->worknode[i].EnterTime = time(NULL);									//�i�J�ɶ��]�w(�Ѭd���`�ǿ�q��) 
		//printf("%ld\n",Mbandwidth->worknode[i].EnterTime);
		printf("%s",ctime(&Mbandwidth->worknode[i].EnterTime));
		
		Mbandwidth->leftBW = Mbandwidth->leftBW - Mbandwidth->worknode[i].bandwidth;	// "�s��" �Ѿl�W�e = �Ѿl�W�e- �ӪA�ȩҰt�o�W�e
		printf("�Ѿl�W�e�j�p=%f\n",Mbandwidth->leftBW);
		
        if(Mbandwidth->leftBW > Mbandwidth->MAXBW) 
            system("pause") ;
        return 1;
	}
	else   // �즳�W�e����,�h�V�{�b�ϥΪ�service�n�W�e					
	{
        printf("�Ѿl�W�e�j�p=%f\n",Mbandwidth->leftBW); 
        printf("Check �{���W�e�j�p\n");
        check_bw = Check_BW(Mbandwidth,i); //  check Optimizatal bandwidth
        printf("�̨Υi���X�W�e�j�p=%f\n",check_bw);
        
        //�ثe�s�[�J���H�̤p�W�e���]�w 
        if(check_bw + Mbandwidth->leftBW >= BW_limit[Mbandwidth->worknode[i].service][0] )
		{
		    //Get_BW(Mbandwidth,i);//����W�e ,�]�w�U�W�e����᪺�s��,�^�ǧ�쪺�W�e 
		    //==================
		    Mbandwidth->worknode[i].bandwidth =Get_BW(Mbandwidth,i);	// ����W�e ,�]�w�U�W�e����᪺�s��,�^�ǧ�쪺�W�e
	       	Mbandwidth->worknode[i].flag = 1;
		    // if(Mbandwidth->worknode[i].service==1)  	// ���� FTP �A��                                   
                // Mbandwidth->worknode[i].filesize = 100*((rand()%10)*10) + (rand()%10)+300 ; // FTP �ɮפj�p
            // else if(Mbandwidth->worknode[i].service==2)	// ���� STREAMING �A��
        	    // Mbandwidth->worknode[i].filesize = 300*((rand()%10)*10) + (rand()%10)+300 ; // STREAMING �ɮפj�p
		    // else                                 		// VOIP�����ɮפj�p 
		        // Mbandwidth->worknode[i].filesize = -1;										// VOIP �������ɮ�
				
			if(Mbandwidth->worknode[i].service==1)			// ���� FTP �A��                                  
				//Mbandwidth->worknode[i].filesize = 200*((rand()%10)*10) + (rand()%10)+400 ;	// FTP �ɮפj�p			// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i];							// FTP �ɮפj�p
			else if(Mbandwidth->worknode[i].service==2)		// ���� STREAMING �A��
				//Mbandwidth->worknode[i].filesize = 400*((rand()%10)*10) + (rand()%10)+400 ; 	// STREAMING �ɮפj�p	// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i]; 							// STREAMING �ɮפj�p
			else                                         	// ���� VOIP �A�� 
				//Mbandwidth->worknode[i].filesize = -1;							// VOIP �������ɮ�		// 20100514
				Mbandwidth->worknode[i].filesize = filesize1[i];							// VOIP �������ɮ�
			
		    printf("[%d]��l���ɮפj�p=%ld \n",i,Mbandwidth->worknode[i].filesize);
		
		    Mbandwidth->worknode[i].EnterTime = time(NULL);                 //�i�J�ɶ��]�w(�Ѭd���`�ǿ�q��) 
		    //printf("%ld\n",Mbandwidth->worknode[i].EnterTime);
		    printf("%s",ctime(&Mbandwidth->worknode[i].EnterTime));
		
		    printf("�Ѿl�W�e�j�p=%f\n",Mbandwidth->leftBW);
		    //==================
		    printf("����䥦�A���W�e,�ӷs�W�A��\n"); 
		    return 1;
        }
        else
        {
			cur_time = time(NULL); // �����A�ȥ��ѷ�ɪ��ɶ�
			
			printf("����W�e�����H���ѷs�A�� (�A�����O��%d)  (�A���W�e�һݤ��j�p��%f) \n",Mbandwidth->worknode[i].service,BW_limit[Mbandwidth->worknode[i].service][0]);
            printf("�W�e����,�L�k�s�W�A��.���ݤ@��\n");
			
			if(Mbandwidth->worknode[i].service==1)  			// ���� FTP �A��
			{
				Mbandwidth->worknode[i].FTP_waitTime = cur_time;
				Mbandwidth->worknode[i].FTP_waitCount++;
				if(Mbandwidth->worknode[i].FTP_waitCount == 2)			// �u�����ݤ@��
				{
					Mbandwidth->worknode[i].FTP_sucessful = 1;			// FTP ���Ѧ��ưO���X��
				}
				printf("FTP���Ѯɶ� %s",ctime(&Mbandwidth->worknode[i].FTP_waitTime));
				printf("FTP�A�ȥ��Ѧ��� %d \n",Mbandwidth->worknode[i].FTP_waitCount);
			}
			else if(Mbandwidth->worknode[i].service==2)			// ���� STREAMING �A��
			{	
				Mbandwidth->worknode[i].Streaming_waitTime = cur_time;	
				Mbandwidth->worknode[i].Streaming_waitCount++;
				if(Mbandwidth->worknode[i].Streaming_waitCount == 2)	// �u�����ݤ@��
				{
					Mbandwidth->worknode[i].Streaming_sucessful = 1;	// Streaming ���Ѧ��ưO���X��
				}
				printf("STREAMING���Ѯɶ� %s",ctime(&Mbandwidth->worknode[i].Streaming_waitTime));
				printf("STREAMING�A�ȥ��Ѧ��� %d \n",Mbandwidth->worknode[i].Streaming_waitCount);
			}
			else												// ���� VOIP �A��
			{
				Mbandwidth->worknode[i].VOIP_waitTime = cur_time;
				Mbandwidth->worknode[i].VOIP_waitCount++;
				if(Mbandwidth->worknode[i].VOIP_waitCount == 2)			// �u�����ݤ@��
				{
					Mbandwidth->worknode[i].VOIP_sucessful = 1;			// VOIP ���Ѧ��ưO���X��
				}
				printf("VOIP���Ѯɶ� %s",ctime(&Mbandwidth->worknode[i].VOIP_waitTime));
				printf("VOIP�A�ȥ��Ѧ��� %d \n",Mbandwidth->worknode[i].VOIP_waitCount);
			}
			
			printf("\n");
			Mbandwidth->worknode[i].FTP_waittotal = Mbandwidth->worknode[i].FTP_waitCount; 
			Mbandwidth->worknode[i].Streaming_waittotal = Mbandwidth->worknode[i].Streaming_waitCount; 
			Mbandwidth->worknode[i].VOIP_waittotal = Mbandwidth->worknode[i].VOIP_waitCount;
			
			printf("FTP�A�ȭp���`���Ѧ��� %d \n",Mbandwidth->worknode[i].FTP_waitCount);
			printf("STREAMING�A�ȭp���`���Ѧ��� %d \n",Mbandwidth->worknode[i].Streaming_waitCount);
			printf("VOIP�A�ȭp���`���Ѧ��� %d \n",Mbandwidth->worknode[i].VOIP_waitCount);
			
			printf("\n");
			printf("FTP�A���`���Ѧ��� %d \n",Mbandwidth->worknode[i].FTP_waittotal);
			printf("STREAMING�A���`���Ѧ��� %d \n",Mbandwidth->worknode[i].Streaming_waittotal);
			printf("VOIP�A���`���Ѧ��� %d \n",Mbandwidth->worknode[i].VOIP_waittotal);
			
            return 0;
        }
        //system("pause");
    }
}

main()
{
    int s;						// �P�_�A�ȶü�
    int i,j,count ;
    float total_bw,voip_TBW=0.0;
	
	static int countFlag=0;		// �p�ƥثe�Ҧ��A�Ȫ��`�H��
	static int servicecount=0;	// �A�Ȧ��ƭp��
	
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	char buffer[80],filename[20],filename1[20],filename2[20],filename3[20],filename4[20];
    
	struct tm * timeinfo;
    
	Mbandwidth Mbandwidth;				// ���c�ܼ�
	   
    srand((unsigned)time(NULL));		// ���üƺؤl
	
    param_inital(&Mbandwidth);
    //printf("Mbandwith.MAXBW=%f\n",Mbandwith.MAXBW);
    
	for(i = 0 ; i <100 ; i++)
    {	
		sprintf(filename3,"UseBw1.txt");
		fp4=fopen(filename3,"a+");
		fprintf(fp4,"�Ĥ@���q���t�W�e\n");
		fprintf(fp4,"�s��\t�ϥΪ��p�X��\t�A������\t�A�Ȥ��W�e\t�ɮפj�p\n");
		
		sprintf(filename4,"Service.txt");
		fp5=fopen(filename4,"a+");
		
        // s = rand()%3;						// �d�� 0 ~ 2 
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
													// �s��   �ϥΪ��p�X��  �A������   ���A�Ȥ��W�e�j�p     ���A�ȩҰt�o���ɮפj�p
                    printf("[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);  
					// fprintf(fp4,"[%d]service=%d\tbandwidth=%f\n",j,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth);	// 20100506
					// fprintf(fp4,"[%d]flag=%d\tservice=%d\tbandwidth=%f\tfilesize=%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);	// 20100506s
					fprintf(fp4,"[%d]\t%d\t%d\t%f\t%ld\n",j,Mbandwidth.worknode[j].flag,Mbandwidth.worknode[j].service,Mbandwidth.worknode[j].bandwidth,Mbandwidth.worknode[j].filesize);
					total_bw+=Mbandwidth.worknode[j].bandwidth;		// �ثe�����ϥα����W�e���h��
                }
            }
			servicecount++;
			fprintf(fp4,"******************************************************\n");
			fprintf(fp4,"�A�Ȧ���\t\t�A�ȼƶq\n");
			fprintf(fp4,"%d\t\t%d\n",servicecount,countFlag);
			fprintf(fp4,"\n");
			
			fprintf(fp5,"******************************************************\n");
			fprintf(fp5,"�A�Ȧ���\t\t�A�ȼƶq\n");
			fprintf(fp5,"%d\t\t%d\n",servicecount,countFlag);
			fprintf(fp5,"\n");
			
			countFlag = 0;
			
			fclose(fp4);
			fclose(fp5);
            printf("-------------------------------------------------------\n"); 
            printf("                            total BW  %f   Free_BW=%f\n",total_bw,Mbandwidth.leftBW );
            printf("-------------------------------------------------------\n"); 
		    printf("�[�J Random Number [%d] is %d\n",i,s);
		    if(	service_init(&Mbandwidth,i)>0)
                break;
            else
                sleep(1000);
        }
        
        //=====����C�L====== 
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
		//sleep((rand()%2)*1000);            //�A�Ȫ�����ɶ� !~2
    }
	
	//�p�Ⱓ�Fvoip���W�e 
	/*for(i = 0 ; i <100 ; i++)
    {
        if(Mbandwidth.worknode[i].service==0)
            voip_TBW+=Mbandwidth.VOIPBW_min;
            
    }*/
	//�Ҧ��A�ȳ��i�J�F,�]������^���Ҧ��W�e 

	while(1) // �T�w�j�a�x�A�ȳ�������~�i�H���X�j��
	{
        count=0; // �T�{100�H�A�Ȥ��O�_�٦��s��(�ϥΤ�)  flag-=1
		
		Mbandwidth.leftBW += Free_service(&Mbandwidth);
		
		/**************service_redistribute_Avg *******************/
		service_redistribute_Avg(&Mbandwidth);
		
		sprintf(filename3,"UseBw1.txt");
		fp4=fopen(filename3,"a+");
		fprintf(fp4,"�ĤG���q���t�W�e\n");
		fprintf(fp4,"�s��\t�ϥΪ��p�X��\t�A������\t�A�Ȥ��W�e\t�ɮפj�p\n");
		
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
            //=====����C�L====== 
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
		fprintf(fp4,"�A�Ȧ���\t\t�A�ȼƶq\n");
		fprintf(fp4,"%d\t\t%d\n",servicecount,countFlag);
		fprintf(fp4,"\n");
		
		fprintf(fp5,"******************************************************\n");
		fprintf(fp5,"�A�Ȧ���\t\t�A�ȼƶq\n");
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
			if(Mbandwidth->worknode[i].bandwidth - releaseBW >  BW_info[Mbandwidth->worknode[i].service])//�i�H����W�e 
			{
				Mbandwidth->worknode[i].release_bw=releaseBW;	 // �N�ҧ�� (����) ���W�e ��s(�Ȧs) �ܵ��c�����i����X��BW
				ProvideBW+=releaseBW;
				//Mbandwidth->worknode[i].bandwidth -= releaseBW;
			}else
				printf("[NOTED]�վ��Ӥp������Ŷ�\n");
		}
	}
	
	return ProvideBW;//�̫�����Ŷ��j�p 
}

float Check_BW(Mbandwidth *Mbandwidth,int index)				// �d�ݨ�L�H�� FTP BW �O�_�󴣨ѵ��ڨϥ�
{
    static float ProvideBW;
    ProvideBW=0.0;
    int i=0;
    float BW_info[3]={Mbandwidth->VOIPBW_min,Mbandwidth->FTPBW_min,Mbandwidth->STREAMINGBW_min}; // { 64K , 64K , 640K }
    short BW_gate[3]={0,1,1};
    for(i=0;i<SERVICE_TYPE;i++)
        Mbandwidth->ProvideBW_SUB[i]=0.0;
    
    //check �̨ΤƤj�p 
	for(i=0 ; i <100 ; i ++)
	{
        Mbandwidth->worknode[i].release_bw=0.0;	//�k0,���Ucheck�u����,�i���s�U�� 
        //�W�e������� :1.�u��ftp,streaming 2.�n�A���٦s�b 3.�n�W�e > �ӪA�ȳ̤p�W�e 
        if(BW_gate[Mbandwidth->worknode[i].service]==1 && Mbandwidth->worknode[i].flag == 1 &&
           Mbandwidth->worknode[i].bandwidth > BW_info[Mbandwidth->worknode[i].service])
        {
            Mbandwidth->worknode[i].ratio =  BW_info[Mbandwidth->worknode[i].service] / Mbandwidth->worknode[i].bandwidth ;
            Mbandwidth->ProvideBW_SUB[Mbandwidth->worknode[i].service] += Mbandwidth->worknode[i].bandwidth * (1-(Mbandwidth->worknode[i].ratio +  (1-Mbandwidth->worknode[i].ratio) * Mbandwidth->worknode[i].x ));
            Mbandwidth->worknode[i].release_bw = Mbandwidth->worknode[i].bandwidth * (1-(Mbandwidth->worknode[i].ratio +  (1-Mbandwidth->worknode[i].ratio) * Mbandwidth->worknode[i].x ));	
			//printf("[%d][s%d] provide %f\t",i,Mbandwidth->worknode[i].service,Mbandwidth->ProvideBW_SUB[Mbandwidth->worknode[i].service]);
        }
	}
	// Mbandwidth->ProvideBW_SUB[0] : VOIP �i�����BW  ;       20100418
	// Mbandwidth->ProvideBW_SUB[1] : FTP�i�����BW  ;          20100418
	//Mbandwidth->ProvideBW_SUB[2] : Streaming �i�����BW   20100418
	
	//ProvideBW=Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2];
	printf("�̤j�i���=>%f (%f)(%f)(%f)\n",Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2],Mbandwidth->ProvideBW_SUB[0],Mbandwidth->ProvideBW_SUB[1],Mbandwidth->ProvideBW_SUB[2]);

    //��̤j�i��� < �ӪA�ȳ̤p�W�e��-�Ѿl�̤p�W�e ���� 
    if(Mbandwidth->ProvideBW_SUB[0]+Mbandwidth->ProvideBW_SUB[1]+Mbandwidth->ProvideBW_SUB[2] 
       < BW_info[Mbandwidth->worknode[index].service]-Mbandwidth->leftBW)
        return 0.0; 
        
	//check �u���� 
	float Avoip, As=0.0, Af=0.0;
	float A_ratio[3]={0.0,Af,As};
    float releaseBW;
	releaseBW=0.0;
	
	if(Mbandwidth->ProvideBW_SUB[1]==0)//+1.0�]���ȥ|�ˤ��J���ɷ|�p�ɳ̤p�W�e�@�I�I     	// FTP �A�ȤH�Ƶ���0
	{
		As=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[2];
		
		printf("�ݨD�W�e=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		ProvideBW = Check_States(Mbandwidth,As,Af);
	}
	else if(Mbandwidth->ProvideBW_SUB[2]==0)  								// streaing �A�ȤH�Ƶ���0
	{
		Af=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[1];
		
		printf("�ݨD�W�e=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		ProvideBW = Check_States(Mbandwidth,As,Af);
	}
	else
	{
		Af = ( Mbandwidth->Wf *(BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[1];	// FTP �վ���
		As = ( Mbandwidth->Ws *(BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/) +1.0) / Mbandwidth->ProvideBW_SUB[2];	// Streaming �վ���
		
		//printf("�ݨD�W�e=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
		//ProvideBW = Check_States(Mbandwidth,As,Af);
		
		//static float GiveAS, GiveAf;
		//GiveAS = 0; 
		//GiveAf = 0;
		
		if( As>=1 )
		{		
			As=0.0;
			//GiveAS = Mbandwidth->ProvideBW_SUB[2];	// Streaming �i���Ѥ��W�e
			Af=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/-Mbandwidth->ProvideBW_SUB[2]) +1.0)
				/ Mbandwidth->ProvideBW_SUB[1];
		
			printf("Check_States(Mbandwidth,As,Af) = %f \n Mbandwidth->ProvideBW_SUB[2] =%f\n",Check_States(Mbandwidth,As,Af),Mbandwidth->ProvideBW_SUB[2]);
			
			ProvideBW = Check_States(Mbandwidth,As,Af)+Mbandwidth->ProvideBW_SUB[2];
		}
		else if( Af >=1 )
		{
			Af=0.0;
			//GiveAf = Mbandwidth->ProvideBW_SUB[1];	// FTP �i���Ѥ��W�e
			As=( 1.0 * (BW_info[Mbandwidth->worknode[index].service]/*-Mbandwidth->leftBW*/-Mbandwidth->ProvideBW_SUB[1]) +1.0) 
			/ Mbandwidth->ProvideBW_SUB[2];
			
			printf("Check_States(Mbandwidth,As,Af) = %f\n Mbandwidth->ProvideBW_SUB[1]=%f\n",Check_States(Mbandwidth,As,Af),Mbandwidth->ProvideBW_SUB[1]);
			
			ProvideBW = Check_States(Mbandwidth,As,Af)+Mbandwidth->ProvideBW_SUB[1];
		}
		else //if( As < 1 &&  Af < 1 )
		{
			printf("�ݨD�W�e=%f Af=%f As=%f\n",BW_info[Mbandwidth->worknode[index].service],Af,As);
			ProvideBW = Check_States(Mbandwidth,As,Af);
		}
	}
	
	
	return ProvideBW;//�̫�����Ŷ��j�p 
}

float Get_BW(Mbandwidth *Mbandwidth,int index)						// �u�거�ܪ�BW
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
