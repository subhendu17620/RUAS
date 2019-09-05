function [  ] = S2_Simsons_3by8(a,b,f,n )
h=(b-a)/n;
I=f(a)+f(b);
x(1)=a;
for i=2:3:n
    x(i)=x(1)+(i-1)*h;
    I=I+3*f(x(i));
end
for i=3:3:n
    x(i)=x(1)+(i-1)*h;
    I=I+3*f(x(i));
end
for i=4:3:n
    x(i)=x(1)+(i-1)*h;
    I=I+2*f(x(i));
end
I=((3*h)/8)*I;
fprintf ('the approximate value of the integral is %f\n',I)
syms t
Ie=eval(int(f(t),t,a,b));
fprintf('the exact value of the integral is %f\n',Ie)
e=abs(Ie-I);
fprintf('the error is  %f\n',e)
end

