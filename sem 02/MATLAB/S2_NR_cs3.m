function [] = S2_NR_cs3( x0,f,df)
maxit=100;
tol=10^-8;
x(1)=x0;
for i=1:maxit
    if abs(df(x(i)))<10^-6
        fprintf('Newton-Raphson Method fails to find root')
        break
    end
    x(i+1)=x(i)-f(x(i))/df(x(i));
    if abs(x(i+1)-x(i))<tol
        fprintf('the approx. root is x(%d)=%f\n',i,x(i+1))
        break
    end
    fprintf('Value of x at %d iteration is x(%d)=%f\n',i,i,x(i))
end
% t=linspace(0,2,500);
% y=f(t);
% plot(t,y,x(i+1),0,'r*');
end

