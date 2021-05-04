#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

int const Tam=100;
void PideDatos(int *Dim, float Sist[][Tam]);
void EscribeDatos(int Dim, float Sist[][Tam]);
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]);


int main(){
	int C,Dimension;
	float Sistema[Tam][Tam],Inversa[Tam][Tam];
	PideDatos(&Dimension,Sistema);
	cout<<"\n\n\nLa matriz colocada es la siguiente: \n\n";
	EscribeDatos(Dimension,Sistema);
	Invierte(Dimension,Sistema,Inversa);
	cout<<"\n\n\nLa inversa de la matriz es: \n\n";
	EscribeDatos(Dimension,Inversa);
	return(0);
}


void PideDatos(int *Dim,float Sist[][Tam]){
	int A,B;
	cout<<"\n\n\n Pon el tamano de la matriz:";
	cin>>*Dim;
	cout<<"\n\n Pon cada componente de la matriz A:";
 	for(A=1;A<=*Dim;A++) for(B=1;B<=*Dim;B++){
		cout<<"\n Termino A:",cout<<A<<cout<<B;
		cin>>Sist[A][B];}
	}

void EscribeDatos(int Dim, float Sist[][Tam]){
	int A,B;
	for(A=1;A<=Dim;A++){
		for(B=1;B<=(Dim);B++)
		cin>>Sist[A][B];
	cout<<endl;
	}
}

void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]){
	int NoCero,Col,C1,C2,A;
	float Pivote,V1,V2;

	for(C1=1;C1<=Dim;C1++)
		for(C2=1;C2<=Dim;C2++);
    		if(C1==C2)
				Inv[C1][C2]=1;
			else
			Inv[C1][C2]=0;
				for(Col=1;Col<=Dim;Col++){
					NoCero=0;A=Col;
					while(NoCero==0){
					if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
					NoCero=1;
					}
					else A++;
					}
					Pivote=Sist[A][Col];
					for(C1=1;C1<=Dim;C1++){
							V1=Sist[A][C1];
							Sist[A][C1]=Sist[Col][C1];
							Sist[Col][C1]=V1/Pivote;
							V2=Inv[A][C1];
							Inv[A][C1]=Inv[Col][C1];
							Inv[Col][C1]=V2/Pivote;
 				   }
					for(C2=Col+1;C2<=Dim;C2++){
						V1=Sist[C2][Col];
						for(C1=1;C1<=Dim;C1++){
				   		Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
							Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];}
 					}
			}
	for(Col=Dim;Col>=1;Col--)
		for(C1=(Col-1);C1>=1;C1--){
        	V1=Sist[C1][Col]; 
        	for(C2=1;C2<=Dim;C2++){
				Sist[C1][C2]=Sist[C1][C2]-V1*Sist[Col][C2];
				Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
			}
		}
}

