function [] = S3_n_harmonics( x,y,n,T )

a=[];
b=[];
for i=1:n
    a(i) = (2*sum(y.*cos((i*2*pi*x)/T)))/length(x);
    b(i) = (2*sum(y.*sin((i*2*pi*x)/T)))/length(x);
end
a0 = (2*sum(y))/length(x);
a = [a0 a];
fprintf('a = ');
disp(a);
fprintf('b = ');
disp(b);

syms t 
fs = a(1)/2;
for i=1:n
    fs = fs+a(i+1)*cos((i*2*pi*t)/T)+b(i)*sin((i*2*pi*t)/T);
end
fprintf('the required fourier series is: \n')
disp(vpa(fs,3));
plot(x,y,'o')
hold on
t = linspace(x(1),x(end),1000);
y1=eval(fs);
plot(t,y1,'k')
end

