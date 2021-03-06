#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcgrand.h"

#define Idle 0
#define Busy 1


void depature(double *Sim_Time, double *next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, double *E_Area_Under_Q, double *E_Area_Under_System, int *C_Num_In_Queue, int *E_Num_In_Queue, int *Server_Status, double *C_qDelay, double *E_qDelay, double *C_Time_Arrival,
	double *E_Time_Arrival, double *C_Total_qDelay, double *E_Total_qDelay, int *Num_Custs_Delayed, float *C1_mean_service_time, float *C2_mean_service_time, double *C_sys_delay, double *E_sys_delay, double *C_total_sys_delay, double *E_total_sys_delay, int *C_Arrival_Type,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,double *num_of_C1_full,double *num_of_C2_full,
	double *num_of_D_arr,int *C_Priority);

void C1_arrival(double *Sim_Time, double *C1_next_arr_time, float *C1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, int *C_Num_In_Queue, int *Server_Status, int *E_Num_In_Queue,
	int *C_Q_limit, double *next_dept_time, float *C1_mean_service_time, double *C_Time_Arrival, int *Num_Custs_Delayed, double *num_of_C_full, double *E_Time_Arrival, int *C_Arrival_Type, double *E_Total_qDelay, double *E_qDelay,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,double *num_of_C1_full,double *num_of_C2_full,
	int *C1_priority,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time);

void C2_arrival(double *Sim_Time, double *C2_next_arr_time, float *C2_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, int *C_Num_In_Queue, int *Server_Status, int *E_Num_In_Queue,
	int *C_Q_limit, double *next_dept_time, float *mean_service_time, double *C_Time_Arrival, int *Num_Custs_Delayed, double *num_of_C_full, double *E_Time_Arrival, int *C_Arrival_Type, double *E_Total_qDelay, double *E_qDelay,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,double *num_of_C1_full,double *num_of_C2_full,
	int *C2_priority,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time);

void E_arrival(double *Sim_Time, double *E_next_arr_time, float *E_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *E_Area_Under_Q, double *E_Area_Under_System, int *E_Num_In_Queue, int *Server_Status, int *C_Num_In_Queue,
	int *E_Q_limit, double *next_dept_time, float *mean_service_time, double *E_Time_Arrival, int *Num_Custs_Delayed, double*num_of_E_full, double *C_Time_Arrival, int *C_Arrival_Type, double *C_Total_qDelay, double *C_qDelay,float *C1_mean_service_time, float *C2_mean_service_time,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q,double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,
	double *num_of_C1_full,double *num_of_C2_full,int *C_Priority);


float expon(float mean);
double minimum(double *next_dept_time, double  *C1_next_arr_time, double  *C2_next_arr_time, double *E_next_arr_time);
void reorganize(int *C_Num_In_Queue,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time,double *C_Time_Arrival, int *C_Arrival_Type);
int main()
{
	// Initialize

	double Sim_Time = 0;

	int Server_Status = Idle;

	int Count = 0;//debug

	int C_Num_In_Queue = 0;
	int C1_Num_In_Queue = 0;//new
	int C2_Num_In_Queue = 0;//new
	int E_Num_In_Queue = 0;

	int Num_Custs_Delayed = 0;

	double C_avg_qdelay = 0;
	double C1_avg_qdelay = 0;//new
	double C2_avg_qdelay = 0;//new
	double E_avg_qdelay = 0;

	float C_avg_num_in_queue = 0;
	float C1_avg_num_in_queue = 0;//new
	float C2_avg_num_in_queue = 0;//new
	float E_avg_num_in_queue = 0;

	float C_avg_num_in_system = 0;
	float C1_avg_num_in_system = 0;
	float C2_avg_num_in_system = 0;
	float E_avg_num_in_system = 0;

	float C1_mean_interarrival_time = 0;
	float C2_mean_interarrival_time = 0;
	float E_mean_interarrival_time = 0;

	double next_dept_time = pow(10, 30);
	float mean_service_time = 0;
	float C1_mean_service_time = 0;
	float C2_mean_service_time = 0;

	double C1_next_arr_time = 0;
	double C2_next_arr_time = 0;
	double E_next_arr_time = 0;

	int Num_Delays_Required = 0;

	int C_Q_limit = 0;
	int E_Q_limit = 0;

	int C_K = 0;
	int E_K = 0;

	int C1_priority = 0;
	int C2_priority = 0;
	
	int temp_priority = 0;
	int temp_type = 0;
	double temp_time = 0;
	
	double C_Area_Under_Q = 0;
	double C1_Area_Under_Q = 0;//new
	double C2_Area_Under_Q = 0;//new
	double E_Area_Under_Q = 0;

	double C_Area_Under_System = 0;
	double C1_Area_Under_System = 0;
	double C2_Area_Under_System = 0;
	double E_Area_Under_System = 0;

	double Last_Event_Time = 0;
	double Last_Event_C1_Time = 0;
	double Last_Event_C2_Time = 0;

	double C_Total_qDelay = 0;
	double C1_Total_qDelay = 0;
	double C2_Total_qDelay = 0;
	double E_Total_qDelay = 0;

	double C_qDelay = 0;
	double C1_qDelay = 0;//new
	double C2_qDelay = 0;//new
	double E_qDelay = 0;

	double Time_since_Last_Event = 0;
	double Time_since_Last_C1_Event = 0;
	double Time_since_Last_C2_Event = 0;

	double min_time = 0;

	double num_of_C_arr = 0;
	double num_of_C1_arr = 0;
	double num_of_C2_arr = 0;
	double num_of_E_arr = 0;
	double num_of_D_arr = 0;

	double num_of_C_full = 0;
	double num_of_C1_full = 0;
	double num_of_C2_full = 0;
	double num_of_E_full = 0;

    float Thoughtput =0;
	float C_Pk = 0;
	float C1_Pk = 0;//new
	float C2_Pk = 0;//new
	float E_Pk = 0;

	double C_sys_delay = 0;
	double C1_sys_delay = 0;//new
	double C2_sys_delay = 0;//new
	double E_sys_delay = 0;

	double C_total_sys_delay = 0;
	double C1_total_sys_delay = 0;//new
	double C2_total_sys_delay = 0;//new
	double E_total_sys_delay = 0;

	float C_avg_sys_delay = 0;
	float C1_avg_sys_delay = 0;//new
	float C2_avg_sys_delay = 0;//new
	float E_avg_sys_delay = 0;
	
	

	printf("Enter customer1 mean_interarrival_time\n");
	scanf("%f", &C1_mean_interarrival_time);
	//C1_mean_interarrival_time = 0.5;
	C1_next_arr_time = expon(C1_mean_interarrival_time);

	//printf("Enter customer2 mean_interarrival_time\n");
	//scanf("%f", &C2_mean_interarrival_time);
	C2_mean_interarrival_time = 0.5;
	C2_next_arr_time = expon(C2_mean_interarrival_time);

	//printf("Enter energy mean_interarrival_time\n");
	//scanf("%f", &E_mean_interarrival_time);
	E_mean_interarrival_time = 1.3;
	E_next_arr_time = expon(E_mean_interarrival_time);

	//printf("Enter C1_mean_service_time\n");
	//scanf("%f", &C1_mean_service_time);
	C1_mean_service_time = 1;

	//printf("Enter C2_mean_service_time\n");
	//scanf("%f", &C2_mean_service_time);
	C2_mean_service_time = 2;
	
	//printf("Enter C1_priority\n");
	//scanf("%d", &C1_priority);
	C1_priority = 0;
	
	//printf("Enter C2_priority\n");
	//scanf("%d", &C2_priority);
	C2_priority = 0;

	//printf("Enter num_delays_required\n");
	//scanf("%d", &Num_Delays_Required);
	Num_Delays_Required = 10000000;

	//printf("Enter Customer_K\n");
	//scanf("%d", &C_K);
	C_K = 10;

	C_Q_limit = C_K - 1;

	double C_Time_Arrival[C_Q_limit + 1];

	for (int i = 0; i < C_Q_limit + 1; i++) {
		C_Time_Arrival[i] = 0;
	}

	int C_Arrival_Type[C_Q_limit + 1];

	for (int i = 0; i < C_Q_limit + 1; i++) {

		C_Arrival_Type[i] = 0;
	}
	
	int C_Priority[C_Q_limit + 1];

	for (int i = 0; i < C_Q_limit + 1; i++) {

		C_Priority[i] = 0;
	}

	//printf("Enter Energy_K\n");
	//scanf("%d", &E_K);
	E_K = 10;

	E_Q_limit = E_K - 1;

	double E_Time_Arrival[E_Q_limit + 1];

	for (int i = 0; i < E_Q_limit + 1; i++) {
		E_Time_Arrival[i] = 0;
	}

	//Initialize end

	while (Num_Custs_Delayed < Num_Delays_Required) {
	
		min_time = minimum(&next_dept_time, &C1_next_arr_time, &C2_next_arr_time, &E_next_arr_time);
		
		
		
		if (min_time == next_dept_time) {
		//	printf("D  ");
			
			
			depature(&Sim_Time, &next_dept_time, &Time_since_Last_Event, &Last_Event_Time, &C_Area_Under_Q, &C_Area_Under_System, &E_Area_Under_Q, &E_Area_Under_System, &C_Num_In_Queue, &E_Num_In_Queue, &Server_Status, &C_qDelay, &E_qDelay, C_Time_Arrival,
				E_Time_Arrival, &C_Total_qDelay, &E_Total_qDelay, &Num_Custs_Delayed, &C1_mean_service_time, &C2_mean_service_time, &C_sys_delay, &E_sys_delay, &C_total_sys_delay, &E_total_sys_delay, C_Arrival_Type,
				&C1_Num_In_Queue,&C2_Num_In_Queue,&C1_avg_qdelay,&C2_avg_qdelay,&C1_avg_num_in_queue,&C2_avg_num_in_queue,&C1_Area_Under_Q, &C1_Area_Under_System, &C2_Area_Under_Q, &C2_Area_Under_System, &C1_qDelay,&C2_qDelay,&C1_sys_delay,&C2_sys_delay,
				&C1_total_sys_delay,&C2_total_sys_delay,&C1_avg_sys_delay,&C2_avg_sys_delay,&C1_Total_qDelay,&C2_Total_qDelay,&Last_Event_C1_Time,&Last_Event_C2_Time,&Time_since_Last_C1_Event,&Time_since_Last_C2_Event,&num_of_C1_full,&num_of_C2_full,&num_of_D_arr,C_Priority);
			num_of_D_arr++;
		}
		else if (min_time == C1_next_arr_time) {
		//	printf("C1 ");
			
			
			C1_arrival(&Sim_Time, &C1_next_arr_time, &C1_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time, &C_Area_Under_Q, &C_Area_Under_System, &C_Num_In_Queue, &Server_Status, &E_Num_In_Queue,
				&C_Q_limit, &next_dept_time, &C1_mean_service_time, C_Time_Arrival, &Num_Custs_Delayed, &num_of_C_full, E_Time_Arrival, C_Arrival_Type, &E_Total_qDelay, &E_qDelay,
				&C1_Num_In_Queue,&C2_Num_In_Queue,&C1_avg_qdelay,&C2_avg_qdelay,&C1_avg_num_in_queue,&C2_avg_num_in_queue,&C1_Area_Under_Q, &C1_Area_Under_System, &C2_Area_Under_Q, &C2_Area_Under_System, &C1_qDelay,&C2_qDelay,&C1_sys_delay,&C2_sys_delay,
				&C1_total_sys_delay,&C2_total_sys_delay,&C1_avg_sys_delay,&C2_avg_sys_delay,&C1_Total_qDelay,&C2_Total_qDelay,&Last_Event_C1_Time,&Last_Event_C2_Time,&Time_since_Last_C1_Event,&Time_since_Last_C2_Event,
				&num_of_C1_full,&num_of_C2_full,&C1_priority,C_Priority,&temp_priority,&temp_type,&temp_time);
			//	reorganize(&C_Num_In_Queue,C_Priority,&temp_priority,&temp_type,&temp_time,C_Time_Arrival,C_Arrival_Type);
			num_of_C_arr++;
			num_of_C1_arr++;
		}

		else if (min_time == C2_next_arr_time) {
		//	printf("C2 ");
			
			
			C2_arrival(&Sim_Time, &C2_next_arr_time, &C2_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time, &C_Area_Under_Q, &C_Area_Under_System, &C_Num_In_Queue, &Server_Status, &E_Num_In_Queue,
				&C_Q_limit, &next_dept_time, &C2_mean_service_time, C_Time_Arrival, &Num_Custs_Delayed, &num_of_C_full, E_Time_Arrival, C_Arrival_Type, &E_Total_qDelay, &E_qDelay,
				&C1_Num_In_Queue,&C2_Num_In_Queue,&C1_avg_qdelay,&C2_avg_qdelay,&C1_avg_num_in_queue,&C2_avg_num_in_queue,&C1_Area_Under_Q,&C1_Area_Under_System, &C2_Area_Under_Q, &C2_Area_Under_System, &C1_qDelay, &C2_qDelay, &C1_sys_delay, &C2_sys_delay,
				&C1_total_sys_delay,&C2_total_sys_delay,&C1_avg_sys_delay,&C2_avg_sys_delay,&C1_Total_qDelay,&C2_Total_qDelay,&Last_Event_C1_Time,&Last_Event_C2_Time,&Time_since_Last_C1_Event,&Time_since_Last_C2_Event,
				&num_of_C1_full,&num_of_C2_full, &C2_priority,C_Priority,&temp_priority,&temp_type,&temp_time);
			//	reorganize(&C_Num_In_Queue,C_Priority,&temp_priority,&temp_type,&temp_time,C_Time_Arrival,C_Arrival_Type);
			num_of_C_arr++;
			num_of_C2_arr++;
		}

		else {
		//	printf("E  ");
			
	
			E_arrival(&Sim_Time, &E_next_arr_time, &E_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time, &E_Area_Under_Q, &E_Area_Under_System, &E_Num_In_Queue, &Server_Status, &C_Num_In_Queue,
				&E_Q_limit, &next_dept_time, &mean_service_time, E_Time_Arrival, &Num_Custs_Delayed, &num_of_E_full, C_Time_Arrival, C_Arrival_Type, &C_Total_qDelay, &C_qDelay,&C1_mean_service_time, &C2_mean_service_time,
				&C1_Num_In_Queue,&C2_Num_In_Queue,&C1_avg_qdelay,&C2_avg_qdelay,&C1_avg_num_in_queue,&C2_avg_num_in_queue,&C1_Area_Under_Q, &C1_Area_Under_System, &C2_Area_Under_Q, &C2_Area_Under_System, &C1_qDelay,&C2_qDelay,&C1_sys_delay,&C2_sys_delay,
				&C1_total_sys_delay,&C2_total_sys_delay,&C1_avg_sys_delay,&C2_avg_sys_delay,&C1_Total_qDelay,&C2_Total_qDelay,&Last_Event_C1_Time,&Last_Event_C2_Time,&Time_since_Last_C1_Event,&Time_since_Last_C2_Event,&num_of_C1_full,&num_of_C2_full,C_Priority);
            
			num_of_E_arr++;
		}
	//	Count++;
		//	printf("C1_area_Q= %.8f \n", C1_Area_Under_Q);
	/*	printf("\n");
		printf("count= %d \n", Count);
		printf("sim_time= %.8f \n", Sim_Time);
		printf("E_num_in_queue= %d \n", E_Num_In_Queue);
		printf("C_num_in_queue= %d \n", C_Num_In_Queue);
		printf("C2_num_in_queue= %d \n", C2_Num_In_Queue);
		printf("C1_num_in_queue= %d \n", C1_Num_In_Queue);

		for (int i = 0; i <= C_Num_In_Queue; i++) { 
				printf(" %d ", C_Arrival_Type[i]);
		}
		printf("\n");*/
			// printf("C_total_q_delay= %.8f \n", C_Total_qDelay);
		
		/*for (int i = 0; i <= E_Num_In_Queue; i++) {
			printf(" %.8f ", E_Time_Arrival[i]);
			}
			printf("\n");
			printf("C_Num_In_Queue = \n");*/
		
			/*	printf("\n");
			for (int i = 0; i <= C_Num_In_Queue; i++) {
				printf(" %.8f   ", C_Time_Arrival[i]);
				 //printf("\n");
				printf(" %d   ", C_Arrival_Type[i]);
			 
			 printf(" %d ", C_Priority[i]);
		//	 printf("C_Num_In_Queue = %d",C_Num_In_Queue);
			 printf("\n");
			}
			
			getchar();*/
		}
		
		
	//	printf("E_Num_In_Queue = %d \n", E_Num_In_Queue);
		
	//getchar();
	
	
	if(Server_Status == Busy){
		Sim_Time = next_dept_time;
		Time_since_Last_Event = Sim_Time - Last_Event_Time;
		Last_Event_Time = Sim_Time;
		C_Area_Under_Q += (C_Num_In_Queue) * (Time_since_Last_Event);
		E_Area_Under_Q += (E_Num_In_Queue) * (Time_since_Last_Event);
		C_Area_Under_System += (C_Num_In_Queue + 1) * (Time_since_Last_Event);
		E_Area_Under_System += (E_Num_In_Queue + 1) * (Time_since_Last_Event);
	
		
			Time_since_Last_C1_Event = Sim_Time - Last_Event_C1_Time;
			Last_Event_C1_Time = Sim_Time;
			C1_Area_Under_Q += (C1_Num_In_Queue) * (Time_since_Last_C1_Event);
			C1_Area_Under_System += (C1_Num_In_Queue + 1) * (Time_since_Last_C1_Event);

			Time_since_Last_C2_Event = Sim_Time - Last_Event_C2_Time;
			Last_Event_C2_Time = Sim_Time;
			C2_Area_Under_Q += (C2_Num_In_Queue) * (Time_since_Last_C2_Event);
			C2_Area_Under_System += (C2_Num_In_Queue + 1) * (Time_since_Last_C2_Event);
			
		num_of_D_arr++;
		if (C_Arrival_Type[1] == 1)
		{
		//	C1_Area_Under_Q += (C1_Num_In_Queue) * (Time_since_Last_C1_Event);
		
			E_sys_delay = Sim_Time - E_Time_Arrival[0];
			C_sys_delay = Sim_Time - C_Time_Arrival[0];
			
			C1_sys_delay = C_sys_delay ;
			
			C_total_sys_delay += C_sys_delay;
			C1_total_sys_delay += C1_sys_delay;
	    	E_total_sys_delay +=E_sys_delay;
	    	
	    	
	    
		}

		else if (C_Arrival_Type[1] == 2)
		{
		//	C2_Area_Under_Q += (C2_Num_In_Queue) * (Time_since_Last_C2_Event);
			E_sys_delay = Sim_Time - E_Time_Arrival[0];
			C_sys_delay = Sim_Time - C_Time_Arrival[0];
			
			C2_sys_delay = C_sys_delay ;
			
			C_total_sys_delay += C_sys_delay;
			C2_total_sys_delay += C2_sys_delay;
	    	E_total_sys_delay +=E_sys_delay;
	    	
	    	
		}
	    
	    
	    //	printf(" %.8f ", C_Time_Arrival[0]);
	    //	printf(" %.8f ", E_Time_Arrival[0]);
	    //	printf(" %.8f ", next_dept_time);
		}	
		
	printf("\n");
	printf("sim_time= %.8f \n", Sim_Time);
	printf("num_custs_delayed= %d \n", Num_Custs_Delayed);

	C_avg_qdelay = C_Total_qDelay / Num_Custs_Delayed;
	printf("C_avg_q_delay= %.8f \n", C_avg_qdelay);
	C1_avg_qdelay = C1_Total_qDelay / Num_Custs_Delayed;
//	printf("C1_avg_q_delay= %.8f \n", C1_avg_qdelay);
	C2_avg_qdelay = C2_Total_qDelay / Num_Custs_Delayed;
//	printf("C2_avg_q_delay= %.8f \n", C2_avg_qdelay);
	
	

	C_avg_num_in_queue = C_Area_Under_Q / Sim_Time;
	printf("C_avg_num_in_queue= %.8f \n", C_avg_num_in_queue);
	C1_avg_num_in_queue = C1_Area_Under_Q / Sim_Time;
//	printf("C1_avg_num_in_queue= %.8f \n", C1_avg_num_in_queue);
	C2_avg_num_in_queue = C2_Area_Under_Q / Sim_Time;
//	printf("C2_avg_num_in_queue= %.8f \n", C2_avg_num_in_queue);

	C_avg_num_in_system = C_Area_Under_System / Sim_Time;
	printf("C_avg_num_in_system= %.8f \n", C_avg_num_in_system);
	C1_avg_num_in_system = C1_Area_Under_System / Sim_Time;
//	printf("C1_avg_num_in_system= %.8f \n", C1_avg_num_in_system);
	C2_avg_num_in_system = C2_Area_Under_System / Sim_Time;
//	printf("C2_avg_num_in_system= %.8f \n", C2_avg_num_in_system);
	
	C_avg_sys_delay = C_total_sys_delay / Num_Custs_Delayed;
	printf("C_avg_system_delay= %.8f \n", C_avg_sys_delay);
	C1_avg_sys_delay = C1_total_sys_delay / Num_Custs_Delayed;
//	printf("C1_avg_system_delay= %.8f \n", C1_avg_sys_delay);
	C2_avg_sys_delay = C2_total_sys_delay / Num_Custs_Delayed;
//	printf("C2_avg_system_delay= %.8f \n", C2_avg_sys_delay);
	
	E_avg_qdelay = E_Total_qDelay / Num_Custs_Delayed;
	printf("E_avg_q_delay= %.8f \n", E_avg_qdelay);
	E_avg_num_in_queue = E_Area_Under_Q / Sim_Time;
	printf("E_avg_num_in_queue= %.8f \n", E_avg_num_in_queue);
	E_avg_sys_delay = E_total_sys_delay / Num_Custs_Delayed;
	printf("E_avg_system_delay= %.8f \n", E_avg_sys_delay);
	E_avg_num_in_system = E_Area_Under_System / Sim_Time;
	printf("E_avg_num_in_system = %.8f \n", E_avg_num_in_system);
	

	Thoughtput = num_of_D_arr/Sim_Time;
	printf("Thoughtput = %f \n", Thoughtput);
	
	C_Pk = num_of_C_full / num_of_C_arr;
	printf("C_Pk = %f \n", C_Pk);
	C1_Pk = num_of_C1_full / num_of_C1_arr;
//	printf("C1_Pk = %f \n", C1_Pk);
	C2_Pk = num_of_C2_full / num_of_C2_arr;
//	printf("C2_Pk = %f \n", C2_Pk);
	E_Pk = num_of_E_full / num_of_E_arr;
	printf("E_Pk = %f \n", E_Pk);
	


	return 0;
}

void depature(double *Sim_Time, double *next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, double *E_Area_Under_Q, double *E_Area_Under_System, int *C_Num_In_Queue, int *E_Num_In_Queue, int *Server_Status, double *C_qDelay, double *E_qDelay, double *C_Time_Arrival,
	double *E_Time_Arrival, double *C_Total_qDelay, double *E_Total_qDelay, int *Num_Custs_Delayed, float *C1_mean_service_time, float *C2_mean_service_time, double *C_sys_delay, double *E_sys_delay, double *C_total_sys_delay, double *E_total_sys_delay, int *C_Arrival_Type,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,
	double *num_of_C1_full,double *num_of_C2_full,double *num_of_D_arr,int *C_Priority) {

	*Sim_Time = *next_dept_time;
	
	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*C_Area_Under_Q += (*C_Num_In_Queue) * (*Time_since_Last_Event);
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);
	if(*Server_Status == 0){
		*C_Area_Under_System += (*C_Num_In_Queue) * (*Time_since_Last_Event);
		*E_Area_Under_System += (*E_Num_In_Queue) * (*Time_since_Last_Event);
	}else{
		*C_Area_Under_System += (*C_Num_In_Queue + 1) * (*Time_since_Last_Event);
		*E_Area_Under_System += (*E_Num_In_Queue + 1) * (*Time_since_Last_Event);
	}
	
	*Time_since_Last_C1_Event = *Sim_Time - *Last_Event_C1_Time;
	*Last_Event_C1_Time = *Sim_Time;
	*C1_Area_Under_Q += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);
	if(*Server_Status == 0){
		*C1_Area_Under_System += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);
	}else{
		*C1_Area_Under_System += (*C1_Num_In_Queue + 1) * (*Time_since_Last_C1_Event);
	}

	*Time_since_Last_C2_Event = *Sim_Time - *Last_Event_C2_Time;
	*Last_Event_C2_Time = *Sim_Time;
	*C2_Area_Under_Q += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event); 
	if(*Server_Status == 0){
		*C2_Area_Under_System += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event);
	}else{
		*C2_Area_Under_System += (*C2_Num_In_Queue + 1) * (*Time_since_Last_C2_Event);
	}

	if (*C_Num_In_Queue == 0) {
		*Server_Status = Idle;
		*next_dept_time = pow(10, 30);

		 
	     
	     if (C_Arrival_Type[1] == 1)
		{
		
			*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
			*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
			*C1_sys_delay = *C_sys_delay ;
			
			*C_total_sys_delay += *C_sys_delay;
			*C1_total_sys_delay += *C1_sys_delay;
	    	*E_total_sys_delay +=*E_sys_delay;
		}

		else if (C_Arrival_Type[1] == 2)
		{
			
			*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
			*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
			*C2_sys_delay = *C_sys_delay ;
			
			*C_total_sys_delay += *C_sys_delay;
			*C2_total_sys_delay += *C2_sys_delay;
	    	*E_total_sys_delay +=*E_sys_delay;
		}
	}
	else if (C_Arrival_Type[1] == 1) 
	{
		
		if(*E_Num_In_Queue >= 1 )
		{
			(*Num_Custs_Delayed)++;
			
			
			
			*C_qDelay = *Sim_Time - C_Time_Arrival[1];
			*C1_qDelay = *C_qDelay;
			*E_qDelay = *Sim_Time - E_Time_Arrival[1];
			*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
			*C1_sys_delay = *C_sys_delay ;
		
			*C_Total_qDelay += *C_qDelay;
			*C_total_sys_delay += *C_sys_delay;
			*C1_Total_qDelay += *C1_qDelay;
			*C1_total_sys_delay += *C1_sys_delay;
		
			*E_Total_qDelay += *E_qDelay;
			*E_total_sys_delay += *E_sys_delay;
			
			
			for (int i = 0; i < *C_Num_In_Queue; i++) 
			{
				C_Time_Arrival[i] = C_Time_Arrival[i + 1];
				C_Arrival_Type[i] = C_Arrival_Type[i + 1];
				C_Priority[i]= C_Priority[i + 1];
			}

			for (int i = 0; i < *E_Num_In_Queue; i++)
			{
				E_Time_Arrival[i] = E_Time_Arrival[i + 1];
			}
			(*C_Num_In_Queue)--;
			(*C1_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
		//	*num_of_D_arr++;
			*next_dept_time = *Sim_Time + expon(*C1_mean_service_time);
			
		/*	*Time_since_Last_C1_Event = *Sim_Time - *Last_Event_C1_Time;
			*Last_Event_C1_Time = *Sim_Time;
			*C1_Area_Under_Q += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);*/
			
		}
		else
		{
			*Server_Status = Idle;
			*next_dept_time = pow(10, 30);
			
			if (C_Arrival_Type[1] == 1)
			{
			
				*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
				*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
				*C1_sys_delay = *C_sys_delay ;
			
				*C_total_sys_delay += *C_sys_delay;
				*C1_total_sys_delay += *C1_sys_delay;
	    		*E_total_sys_delay +=*E_sys_delay;
			}

			else if (C_Arrival_Type[1] == 2)
			{
				*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
				*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
				*C2_sys_delay = *C_sys_delay ;
			
				*C_total_sys_delay += *C_sys_delay;
				*C2_total_sys_delay += *C2_sys_delay;
	    		*E_total_sys_delay +=*E_sys_delay;
			}	
		}
		
	}
	else if (C_Arrival_Type[1] == 2) 
	{
		if(*E_Num_In_Queue >= 2)
		{
			(*Num_Custs_Delayed)++;
			
			
			
			*C_qDelay = *Sim_Time - C_Time_Arrival[1];
			*C2_qDelay = *C_qDelay;
			*E_qDelay = *Sim_Time - E_Time_Arrival[1];
			*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
			*C2_sys_delay = *C_sys_delay ;
		
			*C_Total_qDelay += *C_qDelay;
			*C_total_sys_delay += *C_sys_delay;
			*C2_Total_qDelay += *C1_qDelay;
			*C2_total_sys_delay += *C1_sys_delay;
		
			*E_Total_qDelay += *E_qDelay;
			*E_total_sys_delay += *E_sys_delay;
			
			
			for (int i = 0; i < *C_Num_In_Queue; i++) 
			{
				C_Time_Arrival[i] = C_Time_Arrival[i + 1];
				C_Arrival_Type[i] = C_Arrival_Type[i + 1];
				C_Priority[i]= C_Priority[i + 1];
			}

			for (int i = 0; i < *E_Num_In_Queue; i++)
			{
				E_Time_Arrival[i] = E_Time_Arrival[i + 2];
			}
			(*C_Num_In_Queue)--;
			(*C2_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
		//	*num_of_D_arr++;
			*next_dept_time = *Sim_Time + expon(*C2_mean_service_time);
			/*	*Time_since_Last_C2_Event = *Sim_Time - *Last_Event_C2_Time;
				*Last_Event_C2_Time = *Sim_Time;
				*C2_Area_Under_Q += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event);*/
		}
		else
		{
			*Server_Status = Idle;
			*next_dept_time = pow(10, 30);
			if (C_Arrival_Type[1] == 1)
			{
			*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
			*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
			*C1_sys_delay = *C_sys_delay ;
			
			*C_total_sys_delay += *C_sys_delay;
			*C1_total_sys_delay += *C1_sys_delay;
	    	*E_total_sys_delay +=*E_sys_delay;
			}

			if (C_Arrival_Type[1] == 2)
			{
				*E_sys_delay = *Sim_Time - E_Time_Arrival[0];
				*C_sys_delay = *Sim_Time - C_Time_Arrival[0];
			
				*C2_sys_delay = *C_sys_delay ;
			
				*C_total_sys_delay += *C_sys_delay;
				*C2_total_sys_delay += *C2_sys_delay;
	    		*E_total_sys_delay +=*E_sys_delay;
			}
		}
	}
} 
void E_arrival(double *Sim_Time, double *E_next_arr_time, float *E_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *E_Area_Under_Q, double *E_Area_Under_System, int *E_Num_In_Queue, int *Server_Status, int *C_Num_In_Queue,
	int *E_Q_limit, double *next_dept_time, float *mean_service_time, double *E_Time_Arrival, int *Num_Custs_Delayed, double*num_of_E_full, double *C_Time_Arrival, int *C_Arrival_Type, double *C_Total_qDelay, double *C_qDelay,float *C1_mean_service_time, float *C2_mean_service_time,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,
	double *num_of_C1_full,double *num_of_C2_full,int *C_Priority) {

	*Sim_Time = *E_next_arr_time;
	*E_next_arr_time = *Sim_Time + expon(*E_mean_interarrival_time);
	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);
	if(*Server_Status == 0){
		*E_Area_Under_System += (*E_Num_In_Queue) * (*Time_since_Last_Event);
	}else{
		*E_Area_Under_System += (*E_Num_In_Queue + 1) * (*Time_since_Last_Event);
	}

	if (*Server_Status == Idle) 
	{
		if (*C_Num_In_Queue != 0) 
		{
			if (C_Arrival_Type[1] == 1)
			{
				if(*E_Num_In_Queue>=0 )
				{
					
					(*Num_Custs_Delayed)++;
					*Server_Status = Busy;


					*C_qDelay = *Sim_Time - C_Time_Arrival[1];
					*C_Total_qDelay += *C_qDelay;
					
					*next_dept_time = *Sim_Time + expon(*C1_mean_service_time);
					*C1_qDelay = *Sim_Time - C_Time_Arrival[1];
					*C1_Total_qDelay += *C1_qDelay;
					
				
					*Time_since_Last_C1_Event = *Sim_Time - *Last_Event_C1_Time;
					*Last_Event_C1_Time = *Sim_Time;
					*C1_Area_Under_Q += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);
					*C1_Area_Under_System += (*C1_Num_In_Queue + 1) * (*Time_since_Last_C1_Event);
	
					
					E_Time_Arrival[0] = *Sim_Time;
            
					for (int i = 0; i < *C_Num_In_Queue; i++)
					{
						C_Time_Arrival[i] = C_Time_Arrival[i + 1];
						C_Arrival_Type[i] = C_Arrival_Type[i + 1];
						C_Priority[i]= C_Priority[i + 1];
					}
					(*C1_Num_In_Queue)--;
					(*C_Num_In_Queue)--;	
				}
				else
				{
					(*E_Num_In_Queue)++;

					if (*E_Num_In_Queue > *E_Q_limit) 
					{
						(*E_Num_In_Queue)--;
						(*num_of_E_full)++;
					}

					else
					{
						E_Time_Arrival[*E_Num_In_Queue] = *Sim_Time;
					}
				}	
			}
			else if (C_Arrival_Type[1] == 2)
			{
				
				if(*E_Num_In_Queue>=1)
				{
					
					(*Num_Custs_Delayed)++;
					*Server_Status = Busy;


					*C_qDelay = *Sim_Time - C_Time_Arrival[1];
					*C_Total_qDelay += *C_qDelay;
					*next_dept_time = *Sim_Time + expon(*C2_mean_service_time);
					*C2_qDelay = *Sim_Time - C_Time_Arrival[1];
					*C2_Total_qDelay += *C2_qDelay;
				
					(*E_Num_In_Queue)--;
					
					*Time_since_Last_C2_Event = *Sim_Time - *Last_Event_C2_Time;
					*Last_Event_C1_Time = *Sim_Time;
					*C2_Area_Under_Q += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event);
					*C2_Area_Under_System += (*C2_Num_In_Queue + 1) * (*Time_since_Last_C2_Event);
					
					
					E_Time_Arrival[0] = *Sim_Time;
            
					for (int i = 0; i < *C_Num_In_Queue; i++)
					{
						C_Time_Arrival[i] = C_Time_Arrival[i + 1];
						C_Arrival_Type[i] = C_Arrival_Type[i + 1];
						C_Priority[i]= C_Priority[i + 1];
					}
					(*C2_Num_In_Queue)--;
					(*C_Num_In_Queue)--;
				}
				else
				{
					(*E_Num_In_Queue)++;

					if (*E_Num_In_Queue > *E_Q_limit) 
					{
						(*E_Num_In_Queue)--;
						(*num_of_E_full)++;
					}
					else
					{
						E_Time_Arrival[*E_Num_In_Queue] = *Sim_Time;
					}
				}		
			}
		}
		else
		{
			(*E_Num_In_Queue)++;

			if (*E_Num_In_Queue > *E_Q_limit) 
			{

				(*E_Num_In_Queue)--;
				(*num_of_E_full)++;
			}

			else 
			{
				E_Time_Arrival[*E_Num_In_Queue] = *Sim_Time;
			}
		}
    }
 	else
	{
		(*E_Num_In_Queue)++;

		if (*E_Num_In_Queue > *E_Q_limit) 
		{

			(*E_Num_In_Queue)--;
			(*num_of_E_full)++;
		}

		else 
		{

			E_Time_Arrival[*E_Num_In_Queue] = *Sim_Time;
		}
	}
}

void C1_arrival(double *Sim_Time, double *C1_next_arr_time, float *C1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, int *C_Num_In_Queue, int *Server_Status, int *E_Num_In_Queue,
	int *C_Q_limit, double *next_dept_time, float *C1_mean_service_time, double *C_Time_Arrival, int *Num_Custs_Delayed, double *num_of_C_full, double *E_Time_Arrival, int *C_Arrival_Type, double *E_Total_qDelay, double *E_qDelay,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,
	double *num_of_C1_full,double *num_of_C2_full,int *C1_priority,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time) 
{

	*Sim_Time = *C1_next_arr_time;
	*C1_next_arr_time = *Sim_Time + expon(*C1_mean_interarrival_time);
	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Time_since_Last_C1_Event = *Sim_Time - *Last_Event_C1_Time;
	*Last_Event_Time = *Sim_Time;
	*Last_Event_C1_Time = *Sim_Time;
	*C_Area_Under_Q += (*C_Num_In_Queue) * (*Time_since_Last_Event);
	*C1_Area_Under_Q += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);
	if(*Server_Status == 0){
		*C_Area_Under_System += (*C_Num_In_Queue) * (*Time_since_Last_Event);
		*C1_Area_Under_System += (*C1_Num_In_Queue) * (*Time_since_Last_C1_Event);
	}else{
		*C_Area_Under_System += (*C_Num_In_Queue + 1) * (*Time_since_Last_Event);
		*C1_Area_Under_System += (*C1_Num_In_Queue + 1) * (*Time_since_Last_C1_Event);
	}
	
	if (*Server_Status == Idle) 
	{
		if (*E_Num_In_Queue >= 1 && *C_Num_In_Queue==0) 
		{
			(*Num_Custs_Delayed)++;
			*Server_Status = Busy;
			
			*E_qDelay = *Sim_Time-E_Time_Arrival[1];
			*E_Total_qDelay += *E_qDelay;
			
			*next_dept_time = *Sim_Time + expon(*C1_mean_service_time);

			C_Time_Arrival[0] = *Sim_Time;
            
			for (int i = 0; i < *E_Num_In_Queue; i++) 
			{
				E_Time_Arrival[i] = E_Time_Arrival[i + 1];
			}
			(*E_Num_In_Queue)--;
		}
		else 
		{
			(*C_Num_In_Queue)++;
			(*C1_Num_In_Queue)++;
			if (*C_Num_In_Queue > *C_Q_limit) 
			{
				(*C_Num_In_Queue)--;
				(*C1_Num_In_Queue)--;
				(*num_of_C_full)++;
				(*num_of_C1_full)++;
			}

			else 
			{
				C_Time_Arrival[*C_Num_In_Queue] = *Sim_Time;
				C_Arrival_Type[*C_Num_In_Queue] = 1;
				C_Priority[*C_Num_In_Queue] = *C1_priority;
				
				reorganize(C_Num_In_Queue,C_Priority,temp_priority,temp_type,temp_time,C_Time_Arrival,C_Arrival_Type);
			}
		}
	}
	else 
	{
		(*C_Num_In_Queue)++;
		(*C1_Num_In_Queue)++;
		if (*C_Num_In_Queue > *C_Q_limit) {

			(*C_Num_In_Queue)--;
			(*C1_Num_In_Queue)--;
			(*num_of_C_full)++;
			(*num_of_C1_full)++;
		}
		else 
		{

			C_Time_Arrival[*C_Num_In_Queue] = *Sim_Time;
			C_Arrival_Type[*C_Num_In_Queue] = 1;
			C_Priority[*C_Num_In_Queue] = *C1_priority;
			reorganize(C_Num_In_Queue,C_Priority,temp_priority,temp_type,temp_time,C_Time_Arrival,C_Arrival_Type);
		}
	}
}

void C2_arrival(double *Sim_Time, double *C2_next_arr_time, float *C2_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *C_Area_Under_Q, double *C_Area_Under_System, int *C_Num_In_Queue, int *Server_Status, int *E_Num_In_Queue,
	int *C_Q_limit, double *next_dept_time, float *C2_mean_service_time, double *C_Time_Arrival, int *Num_Custs_Delayed, double *num_of_C_full, double *E_Time_Arrival, int *C_Arrival_Type, double *E_Total_qDelay, double *E_qDelay,
	int *C1_Num_In_Queue,int *C2_Num_In_Queue,double *C1_avg_qdelay,double *C2_avg_qdelay,float *C1_avg_num_in_queue,float *C2_avg_num_in_queue,double *C1_Area_Under_Q, double *C1_Area_Under_System, double *C2_Area_Under_Q, double *C2_Area_Under_System, double *C1_qDelay,double *C2_qDelay,double *C1_sys_delay,double *C2_sys_delay,
	double *C1_total_sys_delay,double *C2_total_sys_delay,float *C1_avg_sys_delay,float *C2_avg_sys_delay,double *C1_Total_qDelay,double *C2_Total_qDelay,double *Last_Event_C1_Time,double *Last_Event_C2_Time,double *Time_since_Last_C1_Event,double *Time_since_Last_C2_Event,
	double *num_of_C1_full,double *num_of_C2_full,int *C2_priority,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time) {

	*Sim_Time = *C2_next_arr_time;
	*C2_next_arr_time = *Sim_Time + expon(*C2_mean_interarrival_time);
	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Time_since_Last_C2_Event = *Sim_Time - *Last_Event_C2_Time;
	*Last_Event_Time = *Sim_Time;
	*Last_Event_C2_Time = *Sim_Time;
	*C_Area_Under_Q += (*C_Num_In_Queue) * (*Time_since_Last_Event);
	*C2_Area_Under_Q += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event);
	if(*Server_Status == 0){
		*C_Area_Under_System += (*C_Num_In_Queue) * (*Time_since_Last_Event);
		*C2_Area_Under_System += (*C2_Num_In_Queue) * (*Time_since_Last_C2_Event);
	}else{
		*C_Area_Under_System += (*C_Num_In_Queue + 1) * (*Time_since_Last_Event);
		*C2_Area_Under_System += (*C2_Num_In_Queue + 1) * (*Time_since_Last_C2_Event);
	}
	if (*Server_Status == Idle) 
	{
		if (*E_Num_In_Queue >= 2) 
		{
			(*Num_Custs_Delayed)++;
			*Server_Status = Busy;
			
			*E_qDelay = *Sim_Time-E_Time_Arrival[1];
			*E_Total_qDelay += *E_qDelay;

			*next_dept_time = *Sim_Time + expon(*C2_mean_service_time);

			C_Time_Arrival[0] = *Sim_Time;
            
			for (int i = 0; i < *E_Num_In_Queue; i++) 
			{
				E_Time_Arrival[i] = E_Time_Arrival[i + 2];
			}
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;

		}
		else 
		{
			(*C_Num_In_Queue)++;
			(*C2_Num_In_Queue)++;
			if (*C_Num_In_Queue > *C_Q_limit) 
			{
				(*C_Num_In_Queue)--;
				(*C2_Num_In_Queue)--;
				(*num_of_C_full)++;
				(*num_of_C2_full)++;
			}
			else 
			{

				C_Time_Arrival[*C_Num_In_Queue] = *Sim_Time;
				C_Arrival_Type[*C_Num_In_Queue] = 2;
				C_Priority[*C_Num_In_Queue] = *C2_priority;
				
				reorganize(C_Num_In_Queue,C_Priority,temp_priority,temp_type,temp_time,C_Time_Arrival,C_Arrival_Type);
			}
		}
	}
	else {
		(*C_Num_In_Queue)++;
		(*C2_Num_In_Queue)++;

		if (*C_Num_In_Queue > *C_Q_limit) {

			(*C_Num_In_Queue)--;
			(*C2_Num_In_Queue)--;
			(*num_of_C_full)++;
			(*num_of_C2_full)++;
		}

		else {

			C_Time_Arrival[*C_Num_In_Queue] = *Sim_Time;
			C_Arrival_Type[*C_Num_In_Queue] = 2;
			C_Priority[*C_Num_In_Queue] = *C2_priority;
				
			reorganize(C_Num_In_Queue,C_Priority,temp_priority,temp_type,temp_time,C_Time_Arrival,C_Arrival_Type);
		}
	}


}


float expon(float mean) {
	return -mean * log(lcgrand(1));
}


double minimum(double *next_dept_time, double  *C1_next_arr_time, double  *C2_next_arr_time, double *E_next_arr_time) {
	double min;
	min = *next_dept_time;
	if (min > *C1_next_arr_time) {
		min = *C1_next_arr_time;
	}
	if (min > *C2_next_arr_time) {
		min = *C2_next_arr_time;
	}
	if (min > *E_next_arr_time) {
		min = *E_next_arr_time;
	}

	return min;

}

void reorganize(int *C_Num_In_Queue,int *C_Priority,int *temp_priority,int *temp_type,double *temp_time,double *C_Time_Arrival, int *C_Arrival_Type)
{
	for(int i = *C_Num_In_Queue; i >1; i--)
	{
		if(C_Priority[i]>C_Priority[i-1])
			{
			*temp_priority = C_Priority[i-1];
			C_Priority[i-1] = C_Priority[i];
			C_Priority[i] = *temp_priority;
						
			*temp_type = C_Arrival_Type[i-1];
			C_Arrival_Type[i-1] = C_Arrival_Type[i];
			C_Arrival_Type[i] = *temp_type;
						
			*temp_time = C_Time_Arrival[i-1];
			C_Time_Arrival[i-1] = C_Time_Arrival[i];
			C_Time_Arrival[i] = *temp_time;
			}		
	}
	
}