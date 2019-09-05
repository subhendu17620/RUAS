function [  ] =S1_fac(n)
f=1;
if n>0
    for i=2:n
        f=f*i;
    end
    f
else
    disp('Error')
end

