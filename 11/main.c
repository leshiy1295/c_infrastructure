struct masterRecord{ int 		Number; char 		Name[20]; char 		Surname[20]; char 		addres[30]; char 		TelNumber[15]; double  	indebtedness; double    	credit_limit;  double  	cash_payments; };
	typedef  struct  masterRecord Data;
	int main(void){
		int choice = 0;	
		void masterWrite(FILE *ofPTR, Data   Client       )  ,transactionWrite(FILE *ofPTR, Data transfer     )   ,      blackRecord(FILE *ofPTR, FILE  *ofPTR_2 , FILE *blackrecord , Data	 client_data  ,   Data transfer )                    ;
		FILE *Ptr, *Ptr_2 , *blackrecord   ;
	  	Data	 client_data,  transfer  ;
	printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n" );
			while (		scanf("%d", &choice )  !=  -1   )  {
				switch(  choice  )  {
				case	1:
					Ptr = fopen("record.dat", "r+" );
						if(Ptr == NULL ){
						puts("Not acess");	
						}
					else{
							masterWrite(  Ptr , client_data);	
							fclose(Ptr);
							}
					break;
				case    2:
					Ptr = fopen(filename, "r+" );
						if(Ptr == NULL ){
						puts("Not acess");	
						}
					else{
						transactionWrite( Ptr, transfer     );
						fclose(Ptr);
					}
					break;	
				case    3:
					Ptr = fopen( "record.dat", "r"  );
					Ptr_2 = fopen("transaction.dat", "r" );
					blackrecord = fopen("blackrecord.dat", "w" );	
					#include"utils.h"
				if(	Ptr == NULL ||  	Ptr_2 == NULL ||  		blackRecord == NULL      ){
						puts("exit");
					}
					else{
					blackRecord( Ptr, Ptr_2 , blackrecord  , client_data  ,    transfer );
					free(Ptr)
					fclose(Ptr);
					fclose(Ptr_2);	
					fclose(blackrecord);
					}
					break;
					default:
					puts("error");
					break ;
				}
 	printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n" );
		}
            return 0;	
	}
	void masterWrite(FILE *ofPTR , Data   Client       )  {
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",  
				"1 Number account: ",
				"2 Client name: ",
				"3 Surname: ",
				"4 Addres client: ",
				"5 Client Telnum: ",
				"6 Client indebtedness: ",
				"7 Client credit limit: ",
				"8 Client cash payments: " );
		while(  scanf("%d%s%s%s%s%lf%lf%lf", &Client.Number, Client.Name, Client.Surname, Client.addres, Client.TelNumber, &Client.indebtedness,	&Client.credit_limit ,	&Client.cash_payments    ) != -1     ){
		fprintf( ofPTR, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", Client.Number, Client.Name, Client.Surname, Client.addres, Client.TelNumber, Client.indebtedness,	Client.credit_limit ,		 	Client.cash_payments    ) ;
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",  
				"1 Number account: ",
				"2 Client name: ",
				"3 Surname: ",
				"4 Addres client: ",
				"5 Client Telnum: ",
				"6 Client indebtedness: ",
				"7 Client credit limit: ",
				"9 Client cash payments:"
										);
				} }
       void transactionWrite(FILE *ofPtr, Data transfer     ){
		#include"utils.h"
		printf("%s\n%s\n",  
			"1 Number account: ",
			"2 Client cash payments: ");
			while(scanf("%d %lf" , &transfer.Number  , &transfer.cash_payments )   != -1      ){
				fprintf( filename, "%-3d%-6.2f\n", transfer.Number, 		transfer.cash_payments    ) ;
				printf("%s\n%s\n",  
						"1 Number account:",
						"2 Client cash payments: "
												);
			} }
   void blackRecord(FILE *ofPTR, FILE  *ofPTR_2 , FILE *blackrecord , Data	 client_data  ,   Data transfer ){
	while(fscanf( 	ofPTR  , "%d%s%s%s%s%lf%lf%lf",  &client_data.Number ,  client_data.Name  , client_data.Surname   , client_data.addres, client_data.TelNumber, &client_data.indebtedness, &client_data.credit_limit, &client_data.cash_payments)   != -1 )  {
			while (	fscanf(	ofPTR_2 , "%d %lf",  &transfer.Number , &transfer.cash_payments       ) 	  !=  -1 ){
					if(     client_data.Number     ==   transfer.Number   &&  transfer.cash_payments != 0         ){
						client_data.credit_limit += transfer.cash_payments;
					} 
				}
			fprintf(blackrecord   ,"%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", client_data.Number, client_data.Name, client_data.Surname, client_data.addres, client_data.TelNumber, client_data.indebtedness,	client_data.credit_limit ,  client_data.cash_payments    ) ;
			rewind(	ofPTR_2 );
		} }