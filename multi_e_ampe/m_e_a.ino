//-------------------------------------------------
//  Voltimeter using Arduino and 7 Segments Display
//  Developed by Caio Luiz Gomes
//  Email: caio.alves at cear.ufpb.br
//-------------------------------------------------

// DEFINE
#define r1       1000000;
#define r2       100000;

#define aRef     5;
#define time_ref 500;

#define a_read_v    10;   //Pino da tensão
#define a_read_i    11;   //Pino da corrente

#define p_t 52  //Pinos do ponto da tensão
#define p_c 53  //Pinos do ponto da corrente

//Declaração de portas
int d_t[] = {22,24,26,28}; 
int d_c[] = {23,25,27,29};

//Declaração dos transistores
int trans_t[] = {30,32,34};
int trans_c[] = {31,33,35};

// Global variable
float voltage;
unsigned long millis_ref = 0;

// Voltage Function
float voltage_func(){
	return ((analogRead(a_read_v)*aRef) / 1023.0 * ((r1+r2)/r2));
}

// Ammeter Function
float amper_func()
{
	return ((analogRead(a_read_i)*aRef)/1023.0);

}
void setup()
{
	for (int pin = 0; pin < 4; pin++)
	{
		pinMode(d_t[pin],OUTPUT);
		pinMode(d_c[pin],OUTPUT);
		pinMode(trans_c[pin],OUTPUT);
		pinMode(trans_t[pin],OUTPUT);
	}
	
	pinMode(a_read_v,INPUT);
	pinMode(a_read_i,INPUT);
}

void loop(){

	if((millis()-millis_ref) > time_ref) {
	voltage = voltage_func();
	millis_ref = millis();
	}

    show_v(voltage);
	//Falta mostrar o valor da tensão
}

void show_v(float v)
{
	int d1, d2, n1;

	d1 = v/10;
    disp(d1,1,0,0);
	d2 = (v%10)*10;
	disp2(d2,0,1,0);
	d3 = (v%10)*100;
    disp3(d3,0,0,1);
}
void display_7(int d, int c, int b, int a)
{
	if(d==1){
		digitalWrite(d_t[0],HIGH);
	}
	if(c==1){
		digitalWrite(d_t[1],HIGH);
	}
	if(b==1){
		digitalWrite(d_t[2],HIGH);
	}
	if(a==1){
		digitalWrite(d_t[3],HIGH);
	}
	else{
		for(int i=0;i<=3;i++){
			digitalWrite(d_t[i],LOW);
		}
	}
}

void disp(int di,int t1, int t2, int t3)
{
	//Comutando transistor
	if(t1==1)
	{
		digitalWrite(trans_t[0], HIGH);
	}
	if(t2==1)
	{
		digitalWrite(trans_t[1],HIGH);
	}
	if(t3==1)
	{
		digitalWrite(trans_t[2],HIGH);
	}
	else {
		for(int i =0;i<=2;i++){
	     	digitalWrite(trans_t[i],LOW);
	    }
	}

    //Selecionar numero
	switch(di)
	{
		case 0: {display_7(0,0,0,0); break;}
		case 1: {display_7(0,0,0,1); break;}
		case 2: {display_7(0,0,1,0); break;}
		case 3: {display_7(0,0,1,1); break;}
		case 4: {display_7(0,1,0,0); break;}
		case 5: {display_7(0,1,0,1); break;}
		case 6: {display_7(0,1,1,0); break;}
		case 7: {display_7(0,1,1,1); break;}
		case 8: {display_7(1,0,0,0); break;}
		case 9: {display_7(1,0,0,1); break;}
	}
}