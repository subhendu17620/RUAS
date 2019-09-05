function [ ] = S2_trapezoid(a,b,n,f)
h=(b-a)/n;
s=f(a)+f(b);
for i=1:n-1
    t=a+i*h;
    s=s+2*(f(t));
end
s=s*(h/2);
disp(s)
end

