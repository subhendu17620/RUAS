n=input('Enter the number of books you have: ');
if n==5
    disp('Enough books');
elseif n>5
    disp('more than enough books')
elseif (0<=n)&&(n<5)
    disp('Not enough books');
else
    disp('enter a positive integer')
end
