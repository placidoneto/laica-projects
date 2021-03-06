// Código: "funções de hardware do prejeto Cubo Mágico".
// Autores: Prof.João Moreno(pós doutor em Engenharia Mecânica), Helora(Aluna de Análise e Desenvolvimento de Sistemas), Samara(técnica em Manutenção e Suporte em informática).
#define servo_garra 43 //define o servo garra na porta 43
#define servo_ajuste 3 //define o servo de ajuste na porta 3 (PWM)

//SOLUCAO CUBO --- INICIO
struct Face {
    int face[3][3];
};

typedef struct Cubo {
    struct Face F;
    struct Face U;
    struct Face D;
    struct Face R;
    struct Face L;
    struct Face B;
};

int montando = 0;

int top_1[3];
int top_2[3];

int topI_1[3];
int topI_2[3];

int bottom_1[3];
int bottom_2[3];

int bottomI_1[3];
int bottomI_2[3];


int left_1[3];
int left_2[3];

int leftI_1[3];
int leftI_2[3];

int right_1[3];
int right_2[3];

int rightI_1[3];
int rightI_2[3];




//SOLUCAO CUBO --- FIM

int pino_D0 = 2; //define o sinal do encoder na porta 2
int pulso; //variável que recebe o sinal do encoder 
int ena = 44; //define a "enable A" da ponte H(L298N) na porta 44
int in1 = 45; //define a IN1 da ponte H (L298N) na porta 45
int in2 = 46; //define a IN2 da ponte H (L298N) na porta 46
int fim_movimento = 1; //variável do encoder
int resolvendo = 0;


void setup() {
Serial.begin(9600); //inicia o serial 
pinMode(servo_garra, OUTPUT); //define o servo garra como saída
pinMode(servo_ajuste, OUTPUT); //define o servo de ajuste como saída
pinMode(pino_D0, INPUT); //define o sinal do encoder como entrada 
pulso = 0; //inicia variável em zero
inicio();} 

void loop() {
//teclado();

if(resolvendo == 0){ 
  
// INTEGRANDO
// CONSTRUINDO O CUBO - INICIO
    struct Cubo cubo;

     /*
       Branco(Bottom): 1
       Amarelo(Top): 2
       Verde(Front): 3
       Laranja(Right): 4
       Azul(Back): 5
       Vermelho(Left): 6
     */
   // CONSTRUINDO BOTTON 
    cubo.D.face[0][0] = 4;
    cubo.D.face[0][1] = 1;
    cubo.D.face[0][2] = 1;

    cubo.D.face[1][0] = 3;
    cubo.D.face[1][1] = 1;
    cubo.D.face[1][2] = 1;

    cubo.D.face[2][0] = 3;
    cubo.D.face[2][1] = 1;
    cubo.D.face[2][2] = 1;

     // CONSTRUINDO TOP 
    cubo.U.face[0][0] = 5;
    cubo.U.face[0][1] = 2;
    cubo.U.face[0][2] = 2;

    cubo.U.face[1][0] = 5;
    cubo.U.face[1][1] = 2;
    cubo.U.face[1][2] = 2;

    cubo.U.face[2][0] = 6;
    cubo.U.face[2][1] = 2;
    cubo.U.face[2][2] = 2;

    // CONSTRUINDO FRONT 
    cubo.F.face[0][0] = 2;
    cubo.F.face[0][1] = 4;
    cubo.F.face[0][2] = 4;

    cubo.F.face[1][0] = 2;
    cubo.F.face[1][1] = 3;
    cubo.F.face[1][2] = 3;

    cubo.F.face[2][0] = 2;
    cubo.F.face[2][1] = 3;
    cubo.F.face[2][2] = 3;

     // CONSTRUINDO RIGHT 
    cubo.R.face[0][0] = 3;
    cubo.R.face[0][1] = 3;
    cubo.R.face[0][2] = 3;

    cubo.R.face[1][0] = 4;
    cubo.R.face[1][1] = 4;
    cubo.R.face[1][2] = 4;

    cubo.R.face[2][0] = 4;
    cubo.R.face[2][1] = 4;
    cubo.R.face[2][2] = 4;

    // CONSTRUINDO BACK 
    cubo.B.face[0][0] = 6;
    cubo.B.face[0][1] = 6;
    cubo.B.face[0][2] = 1;

    cubo.B.face[1][0] = 5;
    cubo.B.face[1][1] = 5;
    cubo.B.face[1][2] = 1;

    cubo.B.face[2][0] = 5;
    cubo.B.face[2][1] = 5;
    cubo.B.face[2][2] = 1;

        // CONSTRUINDO LEFT 
    cubo.L.face[0][0] = 6;
    cubo.L.face[0][1] = 6;
    cubo.L.face[0][2] = 3;

    cubo.L.face[1][0] = 6;
    cubo.L.face[1][1] = 6;
    cubo.L.face[1][2] = 3;

    cubo.L.face[2][0] = 6;
    cubo.L.face[2][1] = 6;
    cubo.L.face[2][2] = 3
    ;
    
  // CONSTRUINDO O CUBO - FIM

    primeiraCamada(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
    segundaCamada(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
    cruzAmarela(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
    orientacaoCantos(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
    permutacoesDosCantos(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
    permutacoesDosMeios(cubo.L.face, cubo.F.face, cubo.R.face, cubo.U.face, cubo.D.face, cubo.B.face);
     resolvendo = 1;
 
}
  
}


