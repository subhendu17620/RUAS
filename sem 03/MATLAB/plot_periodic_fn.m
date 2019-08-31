%f(x)={1.5x 0<=x<2
%	{5-x  2<=x<5	
%	{0 5<=x<6
%f(x+6)=f(x)
%plot in the interval [-6,12]

f=@(x) (1.5*x).*(0<=x & x<2).*(2<=x & x<5)+0.*(5<=x&x<6)
x=linspace(0,6,50);
y=f(x)
I=[-6,12]
ry=repmat(y,1,diff(I)/6);
rx=linspace(I(1),I(2),length(ry));
plot(rx,ry)