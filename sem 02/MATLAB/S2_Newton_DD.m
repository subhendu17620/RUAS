function [  ] = S2_Newton_DD( x,y )

n=length(x);
dd=zeros(n,n);
dd(:,1)=y;
for j=2:n
    for i=j:n
        dd(i,j)=(dd(i,j-1)-dd(i-1,j-1))/(x(i)-x(i-j+1));
    end
end
disp(dd)
del=diag(dd);
syms t
sum = del(1);
prod=1;
for i=1:n-1
    prod=prod*(t-x(i));
    sum=sum+prod*del(i+1);
end
f=expand(sum);
fprintf('the required polynomial is: \n ')
disp(f)
t=min(x):0.01:max(x);
z=eval(f);
plot(t,z,'r',x,y,'*')
end

