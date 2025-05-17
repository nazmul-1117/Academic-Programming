# Manchester

bits = [0 0 1 1 0 0];
bitrate = 1;
n = 1000;

T = length(bits) / bitrate;
N = length(bits) * n;
dt = T/N;
t = 0 : dt : T;

x = zeros(1, length(t));

for i = 1 : length(bits)
  if bits(i) == 1
    x((i-1)*n+1 : (i-1)*n+n/2) = 1;
    x((i-1)*n+n/2 : n*i) = -1;

  else
    x((i-1)*n+1 : (i-1)*n+n/2) = -1;
    x((i-1)*n+n/2 : n*i) = 1;
  endif
end;

plot(t, x);
title('Manchester Encoding...');



% Decoding
counter = 0;
result = [];
for i = 1:length(t)
  if counter < t(i)
    counter = counter + 1;
    if x(i) > 0
      result(counter) = x(i);

    else
      result(counter) = 0;
    endif
  endif
end

disp("Data: ");
disp(result);























