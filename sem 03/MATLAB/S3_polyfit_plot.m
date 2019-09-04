% x = [0 1 2 3 4 5];
% y = [9 8 24 28 26 20];
% 
% % straight line fit
% 
% A = polyfit(x,y,1);
% plot(x,y,'ro')
% hold on
% x1 = linspace(min(x),max(x),100);
% y1 = A(1).*x1 + A(2);
% plot(x1,y1,'k')
% 
% % parabolic fit
% A = polyfit(x,y,2);
% plot(x,y,'ro')
% hold on
% x1 = linspace(min(x),max(x),100);
% y1 = A(1).*x1.^2 + A(2).*x1+A(3);
% plot(x1,y1,'g')

% Fit y = a*exp(b*x)
x = [5 6 7 8 9 10];
y = [133 55 23 7 2 2];
z = log(y);
A = polyfit(x,z,1);
a = exp(A(2));
b = A(1);
syms t 
Y = a*exp(b*t);
fprintf('Required curve is Y = ')
disp(vpa(Y,3))
plot(x,y,'ro')
hold on 
x1 = linspace(min(x),max(x),100);
y1 = a.*exp(b.*x1);
plot(x1,y1,'k')

% fit  y = a*(x^b)
x = [5 6 7 8 9 10];
y = [133 55 23 7 2 2];
w = log(x);
z = log(y);
A = polyfit(w,z,1);
a = exp(A(2));
b = A(1);
syms t
Y = a*(t.^b);
fprintf('Required curve is Y = ')
disp(vpa(Y,3))
plot(x,y,'ro')
hold on 
x1 = linspace(min(x),max(x),100);
y1 = a.*(x1.^b);
plot(x1,y1,'g')

% fit  y = a*(b^x)
x = [5 6 7 8 9 10];
y = [133 55 23 7 2 2];
z = log(y);
A = polyfit(x,z,1);
a = exp(A(2));
b = exp(A(1));
syms t
Y = a*(b.^t);
fprintf('Required curve is Y = ')
disp(vpa(Y,3))
plot(x,y,'ro')
hold on 
x1 = linspace(min(x),max(x),100);
y1 = a.*(b.^x1);
plot(x1,y1,'k')