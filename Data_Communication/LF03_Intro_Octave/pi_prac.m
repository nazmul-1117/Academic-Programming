x = -pi : 0.1 : pi;
y = sin(x);

plot(x, y, "b+");
title("Sine Wave Plot from -π to π");
xlabel("x");
ylabel("sin(x)");
grid on;
