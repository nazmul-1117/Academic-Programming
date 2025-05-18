bits = [1 0 1 0 0 0 1];
bitrate = 1;
n = 1000;

T = length(bits) / bitrate;
N = length(bits) * n;
dt = T/N;
t = 0 : dt : T;

x = zeros(1, length(t));
bit = 1;
first_half = -1;
second_half = 0;

for i = 1 : length(bits)
   if bits(i) == 1
    first_half = -bit;
    second_half = bit;

  else
    first_half = bit;
    second_half = -bit
  endif
  x((i-1)*n+1 : (i-1)*n+n/2) = first_half;
  x((i-1)*n+n/2 : n*i) = second_half;
end

plot(t, x);
grid on;



# decode
counter = 0;
lastbit = 1;
result = [];

for i = 1: length(t)
  if counter < t(i)
    counter = counter+1;
    if x(i) > 0
      result(counter) = 0;
    else
      result(counter) = 1;
    endif
  endif
end
disp(result);





















