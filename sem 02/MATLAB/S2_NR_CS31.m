function[ ] = S2_NR_CS31(x0,f,df)
maxit=100;
tol=10^(-8);
x(1)=x0;
for i=1:maxit
    if abs(df(x(i)))<10^(-6)
        fprintf('Newton-Raphson method fails to find root\n')
        break
    end
    x(i+1)=x(i)-f(x(i))/df(x(i));
    if abs(x(i+1)-x(i))<tol
        fprintf('The approximate root of the given equation is x(%f)\n',x(i+1))
        break
    end
fprintf('Value of x at %d iteration is x(%d)=%f\n',i,i,x(i))
end
% t=linspace(4,6,500);
% y=f(t);
% plot(t,y,x(i+1),0,'*')
end