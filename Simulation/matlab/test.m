clear all;
ftp = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;];
stm = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;3;3;0;0;0;0;0;0;0;0;0;2;0;0;0;12;0;0;0;0;0;0;0;0;3;0;0;1;0;0;0;0;];
vop = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;];

ftp_remo = [0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;4;1;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;2;0;0;0;0;0;0;0;1;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;3;0;0;0;0;0;0;0;0;0;0;0;1;0;0;2;0;0;];
stm_remo = [0;0;0;0;0;0;3;0;0;0;0;0;0;2;2;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;4;0;0;0;0;0;3;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;4;0;0;0;0;1;1;2;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;3;0;0;0;0;0;0;0;0;0;0;0;];
vop_remo = [0;0;0;0;0;0;0;1;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;1;0;0;1;0;0;0;0;0;0;0;0;0;2;0;0;0;0;0;0;0;0;0;0;0;0;3;0;0;0;1;0;3;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;3;0;0;0;0;0;0;0;0;2;0;0;0;0;0;0;];

x = 1:100;

%**************************************************************************

subplot(3, 1, 1);
plot (x, ftp,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('Ftp');
ylim([-1 20]);

subplot(3, 1, 2);
plot (x, stm,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('Streaming');
ylim([-1 20]);;

subplot(3, 1, 3);
plot (x, vop,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('VoIP');
ylim([-1 20]);

%**************************************************************************

figure;
subplot(3, 1, 1);
plot (x, ftp_remo,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('Ftp');
ylim([-1 20]);

% figure;
subplot(3, 1, 2);
plot (x, stm_remo,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('Streaming');
ylim([-1 20]);

% figure;
subplot(3, 1, 3);
plot (x, vop_remo,'.-');
xlabel('Request Number');
ylabel('Waiting Time');
title('VoIP');
ylim([-1 20]);

%**************************************************************************

figure;
plot(x, stm_remo, '*g-', x, stm, '.r-');
legend('Without our method','With our method');
xlabel('Request Number');
ylabel('Waiting Time');
% title('stm 礚诀 vs stm Τ诀 单Ω计');
ylim([-1 18]);

%**************************************************************************

figure;
plot(x, ftp_remo, '.r-', x, stm_remo, '*b-', x, vop_remo, 'xg-');
legend('Ftp','Streaming','VoIP');
xlabel('Request Number');
ylabel('Waiting Time');
% title('Without our method vs wait times');
ylim([-1 7]);

%**************************************************************************

figure;
plot(x, ftp, '.r-', x, stm, '*b-', x, vop, 'xg-');
legend('Ftp','Streaming','VoIP');
xlabel('Request Number');
ylabel('Waiting Time');
% title('With our method vs wait times计');
ylim([-1 18]);

%**************************************************************************
stm_wait = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;0;0;0;0;0;0;0;0;1;1;1;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;1;1;1;1;1;0;0;0;0;];
stm_wait_count = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;2;1;2;1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;16;17;0;0;0;0;0;0;0;0;1;2;3;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;1;2;3;4;5;0;0;0;0;];
stm_people = [1;2;3;4;5;5;6;7;7;8;9;10;11;12;13;14;14;14;15;16;17;18;19;19;20;21;21;22;22;23;24;25;25;25;26;27;27;28;28;29;30;29;30;31;31;30;31;32;33;34;34;34;35;36;36;36;35;36;37;38;39;38;39;39;40;41;41;41;41;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;39;35;36;37;38;39;40;41;41;42;42;42;41;42;43;43;42;43;44;40;40;40;40;40;40;40;40;41;41;41;41;41;42;42;42;42;];

total = sum(stm)
sizeof1 = size(find(stm>=1))
sizeof2 = size(stm)
time_len = sizeof2-sizeof1 +total

x1 = 1:124;

figure;
% subplot(2,1,1)
% plot (x1, stm_wait, '.r-');
% xlabel('Time');
% ylabel('Wait');
% ylim([0 1.5]);

subplot(2,1,1)
plot (x1, stm_people, '.r-');
xlabel('Time');
ylabel('People');
ylim([0 45]);

subplot(2,1,2)
plot (x1, stm_wait_count, '.b-');
xlabel('Time');
ylabel('Waiting Time');
ylim([0 18]);

% plot (x1, stm_wait, '.r-', x1, stm_wait_count, '*b-');
% legend('Wait','Waiting Time');
% xlabel('Time');
% ylabel('Wait vs Waiting Time');
% title('Streaming Τ诀单丁vsΩ计');
% ylim([0 18]);


%************************************************************************ 

% subplot(3,1,1)
% plot (x1, stm_wait, '.r-');
% xlabel('丁');
% ylabel('单');
% title('stm Τ诀单丁');
% ylim([0 1]);
% 
% subplot(3,1,2)
% plot (x1, stm_wait_count, '*b-');
% xlabel('丁');
% ylabel('Ω计');
% title('stm Τ诀单Ω计');
% ylim([0 18]);
% 
% subplot(3,1,3)
% plot (x1, stm_wait, '.r-', x1, stm_wait_count, '*b-');
% legend('单','Ω计');
% xlabel('丁');
% ylabel('单vsΩ计');
% title('stm Τ诀单丁vsΩ计');
% ylim([0 18]);

%**************************************************************************
stm_remo_wait = [0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;1;1;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;0;0;0;0;0;1;1;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;1;1;1;0;1;1;1;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;1;1;1;0;0;0;0;0;0;1;0;0;0;0;];
stm_remo_wait_count = [0;0;0;0;0;0;0;0;0;0;0;0;0;1;2;1;2;3;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;2;0;0;0;0;0;1;2;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;2;3;4;5;0;1;1;2;3;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;2;3;4;5;0;0;0;0;0;0;1;0;0;0;0;];
stm_remo_people = [1;2;3;3;4;4;5;4;5;6;7;8;9;8;8;8;8;8;9;9;10;8;9;8;9;9;10;10;10;10;10;10;10;10;10;9;10;10;11;11;12;11;9;10;11;12;12;11;12;13;14;11;12;12;12;12;13;13;14;15;16;16;17;17;16;17;16;13;13;12;12;12;13;13;13;13;14;15;15;15;15;15;16;16;14;14;15;16;15;15;13;14;15;15;14;14;14;15;15;15;15;15;15;15;15;13;14;14;14;14;15;14;14;14;14;];

total1 = sum(stm_remo)
sizeof3 = size(find(stm_remo>=1))
sizeof4 = size(stm_remo)
time_len1 = sizeof4-sizeof3 +total1

x2 = 1:115;

figure;
% subplot(2,1,1)
% plot (x2, stm_remo_wait, '.r-');
% xlabel('Time');
% ylabel('Wait');
% % title('stm 礚诀单Ω计');
% ylim([0 1.5]);

subplot(2,1,1)
plot (x2, stm_remo_people, '.r-');
xlabel('Time');
ylabel('People');
% title('stm 礚诀单Ω计');
ylim([0 18]);

subplot(2,1,2)
plot (x2, stm_remo_wait_count, '.b-');
xlabel('Time');
ylabel('Waiting Time');
% title('stm 礚诀单Ω计');
ylim([0 5]);


% figure;
% subplot(3,1,1)
% plot (x2, stm_remo_wait, '.r-');
% xlabel('丁');
% ylabel('单');
% title('stm 礚诀单丁');
% ylim([0 1]);
% 
% subplot(3,1,2)
% plot (x2, stm_remo_wait_count, '*b-');
% xlabel('丁');
% ylabel('Ω计');
% title('stm 礚诀单Ω计');
% ylim([0 5]);
% 
% subplot(3,1,3)
% plot (x2, stm_remo_wait, '.r-', x2, stm_remo_wait_count, '*b-');
% legend('单','Ω计');
% xlabel('丁');
% ylabel('单vsΩ计');
% title('stm 礚诀单丁vsΩ计');
% ylim([0 5]);

%**************************************************************************

% packet loss ; ftp_remo>1:单
size(find(ftp_remo>1))/size(ftp_remo)
size(find(ftp>1))/size(ftp)

size(find(stm_remo>1))/size(stm_remo)
size(find(stm>1))/size(stm)

size(find(vop_remo>1))/size(vop_remo)
size(find(vop>1))/size(vop)


%fail
ftp_fail = size(find(ftp>1))/size(find(ftp>=0))*100
ftp_remo_fail = size(find(ftp_remo>1))/size(find(ftp_remo>=0))*100

stm_fails = size(find(stm>1))/size(find(stm>=0))*100
stm_remo_fail = size(find(stm_remo>1))/size(find(stm_remo>=0))*100

vop_fail = size(find(vop>1))/size(find(vop>=0))*100
vop_remo_fail = size(find(vop_remo>1))/size(find(vop_remo>=0))*100


% success = 1- ( 痷タ单计/璶Τ单计(常衡ア毖) )
ftp_success = (1-size(find(ftp>1))/size(find(ftp>=0)))*100
ftp_remo_success = (1-size(find(ftp_remo>1))/size(find(ftp_remo>=0)))*100

stm_success = (1-(size(find(stm>1))/size(find(stm>=0))))*100
stm_remo_success = (1-size(find(stm_remo>1))/size(find(stm_remo>=0)))*100

vop_success = (1-size(find(vop>1))/size(find(vop>=0)))*100
vop_remo_success = (1-size(find(vop_remo>1))/size(find(vop_remo>=0)))*100


%avg waitting time

%aa1 = sum(stm)
%bb1 = sum(stm_remo)

sum(stm)/100
sum(stm_remo)/100

sum(vop)/100
sum(vop_remo)/100

sum(ftp)/100
sum(ftp_remo)/100
