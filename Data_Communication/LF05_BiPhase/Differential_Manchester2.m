bits= [1 0 1 0];
bitrate = 1;
n = 1000;

T = length(bits)/ bitrate;
N = length(bits) * n;
dt = T/N;
t = 0 : dt : T;

x = zeros(1, length(t));
lastbit = 1;

first_half = -1;
last_half = -1;

for i = 1 : length(bits)
  if bits(i) == 1
    first_half = -lastbit;
    last_half = lastbit;

  else
    first_half = lastbit;
    last_half = -lastbit;
  endif
  x((i-1)*n+1 : (i-1)*n+n/2) = first_half;
  x((i-1)*n+n/2 : n*i) = last_half;
end

plot(t, x);
title('Differential_Manchester...')
grid on;














