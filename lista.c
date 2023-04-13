clear all
clc

fprintf("Questões 1,2,3 e 4 - considere somente os valores dados, não precisa fazer conversões nas dimensões: \n\n");

N=input('Numero de espiras N:');
H1=input('Valor de H1: ');
H2=input('Valor de H2: ');
B1=input('Valor de B1: ');
B2=input('Valor de B2: ');
l1=input('Valor de l (em cm): ');
A1=input('Valor de A (em cm^2): ');
Vef=input('Valor eficaz da tensão indicado na questão 4: ');
fprintf("\n")

%Convesões
Vp = Vef*sqrt(2);
A = A1*10^-4;
l = l1*10^-2;
u1= (B1/H1);
u2= ((B2-B1)/(H2-H1));

%Algoritmos 
L1 = (N^2)/((H1/B1)*(l/A));
Ldois = (N^2)/(((H2-H1)/(B2-B1))*(l/A));
L2 = (N^2)/(((H2-H1)/(B2-B1))*(l/A))*10^3;
Vmax = 2*pi*60*N*B1*A;
Bc = Vp/(2*pi*60*N*A);



if (Vp<=Vmax)
    W = ((l*A*(Bc^2))/(2*u1))*10^6;
else
    W = ((l*A*(Bc^2))/(2*u2))*10^6;
    %OU
    W2 = ((0.5*(Vp^2))/(((2*pi*60)^2)*Ldois))*10^6
end



fprintf('A resposta da questões, já normalizadas, é de: \n questão1 %f H, questão 2: %f mH, questão 3: %f V , questão 4: %f uJ  \n',L1,L2,Vmax,W)
