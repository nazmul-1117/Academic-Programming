bits = [1 0 1];
bitrate = 1;
n = 1000;
T = length(bits)/bitrate;
N = n*length(bits);
dt = T/N;

t = 0:dt:T;
x = zeros(1,length(t));
lastbit = 1;
for i=1:length(bits)
  if bits(i)==1
    x(((i-1)*n)+1:i*n) = -lastbit;
    lastbit = -lastbit;
  else
    x(((i-1)*n)+1:i*n) = lastbit;
  end
end
plot(t, x, 'Linewidth', 3); % Corrected plot option syntax
title('NRZ-I Encoding');
xlabel('Time');
ylabel('Amplitude');
grid on;

counter = 0;
lastbit_decoded = 1; % Renamed to avoid confusion with encoding lastbit
result = [];       % Initialize result as an empty array
for i = 1:length(t)
  if t(i) > counter
    counter = counter + 1/bitrate; % Increment counter by the bit duration
    index = round(i);             % Get the index corresponding to the bit time
    if index <= length(x)
      if x(index) != lastbit_decoded
        result(end+1) = 1;       % Append to the end of the array
        lastbit_decoded = -lastbit_decoded;
      else
        result(end+1) = 0;       % Append to the end of the array
      end
    end
  end
end
disp('NRZ-I Decoding:');
disp(result);
