void teclado(){
  char tecla;
  tecla = Serial.read();
  if (tecla == '1'){frontIClockservo();}
  if (tecla == '2'){frontClockservo();}
  if (tecla == '3'){frontClock180servo();}
  if (tecla == '4'){leftIClockservo();}
  if (tecla == '5'){leftClockservo();}
  if (tecla == '6'){leftClock180servo();}
  if (tecla == '7'){rightIClockservo();}
  if (tecla == '8'){rightClockservo();}
  if (tecla == '9'){rightClock180servo();}
  if (tecla == 'a'){bottomIClockservo();}
  if (tecla == 'b'){bottomClockservo();}
  if (tecla == 'c'){bottomClock180servo();}
  if (tecla == 'd'){backIClockservo();}
  if (tecla == 'e'){backClockservo();}
  if (tecla == 'f'){backClock180servo();}
  if (tecla == 'g'){topIClockservo();}
  if (tecla == 'h'){topClockservo();}
  if (tecla == 'i'){topClock180servo();}
  
  if (tecla == 'k'){
  /*FRONT, COLOCAR NA CONFIGURAÇÃO ABAIXO E EXECUTAR O CÓDIGO
  
    LAR ! LAR ! AM
    VERD! VERD! AM
    VERD! VERD! VERD
   */ 
  rightClockservo();
  topIClockservo();
  rightIClockservo();}
  
  if (tecla == 'l'){
  //CASO SIMPLES 2
  /*FRONT, COLOCAR NA CONFIGURAÇÃO ABAIXO E EXECUTAR O CÓDIGO 
  
    VERD ! LAR ! LAR
     AM  ! VERD! VERD
     AM  ! VERD! VERD
   */ 
  leftIClockservo();
  topIClockservo(); 
  leftClockservo();}
  
  if (tecla == 'm'){//PASSOU
  //CASO MÉDIO 1
  /*FRONT (PECA DA 2 CAMADA PRA ESQUERDA), COLOCAR NA CONFIGURAÇÃO ABAIXO E EXECUTAR O CÓDIGO
  
    VERD ! VERM ! LAR
     AM  ! VERM ! VERM
    VERM ! VERM ! VERM
   */
  topIClockservo();
  leftIClockservo();
  topIClockservo();
  leftClockservo();
  topClockservo();
  frontClockservo();
  topClockservo();
  frontIClockservo();}
  
  if (tecla == 'n'){//PASSOU
  //CASO MÉDIO 2
  /*FRONT (PECA DA 2 CAMADA PRA DIREITA), COLOCAR NA CONFIGURAÇÃO ABAIXO E EXECUTAR O CÓDIGO
  
    VERD ! VERM ! LAR
    VERM ! VERM !  AM
    VERM ! VERM ! VERM
   */
  topClockservo();
  rightClockservo();
  topClockservo();
  rightIClockservo();
  topIClockservo();
  frontIClockservo();
  topIClockservo();
  frontClockservo();} 
  
  if (tecla == 'o'){
  //Cruz amarela 
  frontClockservo();
  rightClockservo(); 
  topClockservo();
  rightIClockservo();
  topIClockservo(); 
  frontIClockservo();}
  
  if (tecla == 'q'){
  //completa parte de cima
  rightClockservo();  
  topClockservo();
  rightIClockservo();  
  topClockservo();
  rightClockservo();
  topClock180servo(); 
  rightIClockservo();}
  
  if (tecla == 'r'){
  //penultimo passo  
  rightClockservo();
  backIClockservo(); 
  rightClockservo();
  frontClock180servo(); 
  rightIClockservo();
  backClockservo();
  rightClockservo();
  frontClock180servo(); 
  rightClock180servo();}
  
  if (tecla == 's'){
  //ultimo passo caso 1  
  frontClock180servo(); 
  topClockservo();
  leftClockservo();
  rightIClockservo(); 
  frontClock180servo();
  leftIClockservo(); 
  rightClockservo(); 
  topClockservo();
  frontClock180servo();}

  if (tecla == 't'){
  //ultimo passo caso 1  
  frontClock180servo(); 
  topIClockservo();
  leftClockservo();
  rightIClockservo(); 
  frontClock180servo();
  leftIClockservo(); 
  rightClockservo(); 
  topIClockservo();
  frontClock180servo();}  
}
