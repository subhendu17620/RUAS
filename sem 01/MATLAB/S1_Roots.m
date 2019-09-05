function [  ] = S1_Roots(a,b,c)
D= b^2 - 4*a*c;
if(D>0)
    disp('roots are real and are unequal');
elseif(D==0)
    disp('roots are real and equal');
else
    disp('roots are imaginary');
end

