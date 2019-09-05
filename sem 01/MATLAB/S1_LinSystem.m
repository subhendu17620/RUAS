function [  ] = S1_LinSystem(A,B )

M=[A B];
ra= rank(A);
rm=rank(M);
[m, n]=size(A);
if ra==rm 
    disp('system is consisten');
    if ra==n
        disp('It has unique solutions');
        x=inv(A)*B;
        disp(x);
    else 
        disp('it has infinite solution');
        fprintf(rref(M));
    end
else 
    disp('System is in consistent, no solution');
end
end

