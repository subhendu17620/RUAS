function [ ] = S1_fibonacci( n )
a=0;
b=1;
disp(a)
disp(b)
for i=1:n
   c=a+b;
   a=b;
   b=c;
   disp(c)
end
end

