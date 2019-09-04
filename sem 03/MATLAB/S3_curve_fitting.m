function [] = S3_curve_fitting( f,i,I )
x = linspace(i(1),i(2),100);
y = repmat(f(x),1,diff(I)/diff(i));
x = linspace(I(1),I(2),length(y));
plot(x,y,'g')
end