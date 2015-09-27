% matlab script to read sincos.txt and plot columns 3 (cos) & 4 (sin) against
% column 2 (angle)

ifs=fopen('sincos.txt')            % open the file 
C = textscan(ifs, '%*d %f %f %f');  % skip col 1, read cols 2-4
x=C{1};         % copy first col into x
y1=C{2};        % copy 2nd col (cos) in y1 
y2=C{3};        % copy 3rd col (sin) into y2
figure(1);
plot(x,y1,'b-',x,y2,'r-');      % plot y1 & y2 agains x
xlabel('theta (radians)')       % label the axes
ylabel('f(theta)')
legend('cos(theta)','sin(theta)')   % and add a legend