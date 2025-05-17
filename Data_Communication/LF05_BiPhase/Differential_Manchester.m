# Differential Manchester

bits = [0 0 1 1 0 0];
bitrate = 1;
n = 1000;

T = length(bits) / bitrate;
N = length(bits) * n;
dt = T/N;
t = 0 : dt : T;

x = zeros(1, length(t));
current_level = 1; % Initial level (can be +1 or -1)

for i = 1 : length(bits)
  if bits(i) == 1
    % Transition at the beginning of the bit interval
    first_half_level = -current_level;
    second_half_level = current_level;
    current_level = first_half_level; % Update for the next bit
  else
    % No transition at the beginning of the bit interval
    first_half_level = current_level;
    second_half_level = current_level;
  endif
  x((i-1)*n+1 : (i-1)*n+n/2) = first_half_level;
  x((i-1)*n+n/2 : n*i) = second_half_level;
end;

plot(t, x, 'LineWidth', 2);
title('Differential Manchester Encoding');
xlabel('Time');
ylabel('Amplitude');
grid on;
ylim([-1.5 1.5]);

% Decoding
result = [];
previous_level_start = 1; % Assume initial level at the start of the transmission
for i = 1 : length(bits)
  % Sample the level at the beginning of the bit interval
  start_sample_index = round((i - 1) * n + 1);
  if start_sample_index <= length(x)
    current_level_start = sign(x(start_sample_index)); % Get the sign (+1 or -1)
  end

  % Sample the level at the middle of the bit interval
  middle_sample_index = round((i - 1) * n + n / 2);
  if middle_sample_index <= length(x)
    current_level_middle = sign(x(middle_sample_index));

    if current_level_start ~= current_level_middle
      result(i) = 1; % Transition indicates '1'
    else
      result(i) = 0; % No transition indicates '0'
    endif
    previous_level_start = current_level_middle; % For the next bit's comparison
  end
end

disp("Differential Manchester Decoding:");
disp(result);
