% I = [0,8];
% x = linspace(0,2,100);
% f = @(x) exp(3*x);
% y = repmat(f(x),1,diff(I)/2);
% x = linspace(0,8,length(y));
% plot(x,y)

% f = @(x) (2-x).*(0<=x & x<3) + (-1).*(3<=x & x<5);
% x = linspace(0,5,100);
% I = [-5,5];
% y = repmat(f(x),1,diff(I)/5);
% x = linspace(-5,5,length(y));
% plot(x,y)

f = @(x) (1.5*x).*(0<=x & x<2) + (5-x).*(2<=x & x<5)+ 0.*(5<=x & x<6);
x = linspace(0,6,100);
I = [-6,12];
y = repmat(f(x),1,diff(I)/6);
x = linspace(I(1),I(2),length(y));
plot(x,y,'g')