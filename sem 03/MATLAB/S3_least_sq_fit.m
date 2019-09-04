function [  ] = S3_least_sq_fit( x,y )
xi=sum(x);
xi2 = sum(x.^2);
yi = sum(y);
xiyi = sum(x.*y);
M = [xi2 xi;xi length(x)];
N = [xiyi;yi];
x = M\N;
disp(x)
end

