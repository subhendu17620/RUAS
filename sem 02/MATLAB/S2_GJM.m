function [ ] = S2_GJM( x,A,B )
maxit=100;
[n,~]=size(A);
tol=10^-8;
flag=1;
y=x;
for k=1:n
    if abs(A(k,k))<sum(abs(A(k,:)))-abs(A(k,k)) %check diagonal dominance
        fprintf('it is not diagonally dominant\n')
        flag=0;
        break
    end
end
if flag~=0
    for i=1:maxit
        for k=1:n
            num=B(k,:)-A(k,1:k-1)*x(1:k-1)-A(k,k+1:n)*x(k+1:n);
            y(k)=num/A(k,k);
        end
        err=max(abs(y-x));
        x=y;
        if err<tol
            fprintf('The approx. sol is converging\n')
            break
        end
        fprintf('The error after %f iteration is err= %f\n',i,err)
    end
    fprintf('The approx. sol after %f iteration is\n x= ',i)
    disp(x)
end
end

