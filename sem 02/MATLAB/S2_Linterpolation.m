function [  ] = S2_Linterpolation( x,v)
n=length(x);
syms t
sum=0;
for i=1:n
    l=1;
    for j=1:n
        if i~=j
            l=l*(t-x(j))/(x(i)-x(j));
        end
    end
    sum=sum+l*v(i);
end
poly=expand(sum);
disp('the polynomial is :')
disp(poly)
disp('the value of function at x=7 is:')
disp(subs(poly,t,7))
t1=0:0.01:8;
plot(subs(poly,t,t1),t1)
hold on
plot(v,x,'r*')
end

