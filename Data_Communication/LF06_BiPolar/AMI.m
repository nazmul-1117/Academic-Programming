bits = [1 0 1 0 0 1 0];
bitrate  = 1;
n = 1000;

T = length(bits) / bitrate;
N = length(bits) * n;
dt = T/N;
t = 0 : dt : T;

x = zeros(1, length(t));
lastbit = -1;

for i = 1 : length(bits)
  if bits(i) == 1
    x((i-1)*n+1 : n*i) = -lastbit;
    lastbit = -lastbit;
  endif
end

plot(t, x, 'LineWidth', 3);
title("AMI encoding...");
grid on;


% Decoding...
counter = 0;
lastbit = 1;
result = [];

for i = 1 : length(t)
  if counter < t(i)
    counter = counter + 1;
    if x(i) == -lastbit
      result(counter) = 1;
      lastbit = -lastbit;

    else
      result(counter) = 0;
    endif
  endif
end


disp("Bits: ");
disp(result);

























