x = linspace(0,4,100);
f = @(x) x;
y = f(x);
I = [-8,8];
y1 = repmat(f(x),1,diff(I)/4);
x1 = linspace(-8,8,length(y1));
plot(x1,y1)
