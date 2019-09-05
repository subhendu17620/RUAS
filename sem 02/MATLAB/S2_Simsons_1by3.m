function [  ] = S2_Simsons_1by3(a,b,f,n )
h=(b-a)/n;
I=f(a)+f(b);
x=a;
for i=2:2:n
    x(i)=x(1)+(i-1)*h;
    I=I+4*f(x(i));
end
for i=3:2:n
    x(i)=x(1)+(i-1)*h;
    I=I+2*f(x(i));
end
I=h/3*I;
fprintf ('the approximate value of the integral is %f\n',I)
syms t
Ie=eval(int(f(t),t,a,b));
fprintf('the exact value of the integral is %f\n',Ie)
e=abs(Ie-I);
fprintf('the error is  %f\n',e)
end

