function [ ] = S1_fib( n )
f(1)=1;
f(2)=1;
i=1;
while f(i)<n
    f(i)=f(i-1)+f(i-2);
end
disp(f)
end

