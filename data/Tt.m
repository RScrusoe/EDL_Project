% A=xlsread('Tt_65.xlsx');
% B=xlsread('Tt_90.xlsx');
% C=xlsread('Tt_11.xlsx');
% plot(A(:,1),A(:,2),'Color','r');
% hold on
% plot(B(:,1),B(:,2),'Color','g');
% hold on
% plot(C(:,1),C(:,2),'Color','b');
% legend('T=65*','T=90*','T=11');
% xlabel('Time (in seconds)')
% ylabel('Temperture (in degree Celcius)')
 
IV_50=xlsread('iv_50.xlsx');
plot(IV_50(:,2),(IV_50(:,3)/0.33));

% IV_45=xlsread('iv_45.xlsx');
% hold on;
% plot(IV_45(:,2),(IV_45(:,3)/0.33),'Color','r');

IV_90=xlsread('iv_90.xlsx');
hold on
plot(IV_90(:,2),(IV_90(:,3)/0.33),'Color','g');

IV_26=xlsread('iv_26.xlsx');
hold on
plot(IV_26(:,2),(IV_26(:,3)/0.33),'Color','black');

IV_15=xlsread('iv_15.xlsx');
hold on
% scatter(IV_15(:,2),(IV_15(:,3)/0.33));
% 
% Fit = polyfit(IV_15(:,2),IV_15(:,3),1);
% plot(Fit,IV_15(:,2),IV_15(:,3));
axis([0 1.5  -0.1 4])

% hold on
% plot(A(:,6),A(:,7),'Color','m');
% hold on
% plot(A(:,10),A(:,11),'Color','r');




