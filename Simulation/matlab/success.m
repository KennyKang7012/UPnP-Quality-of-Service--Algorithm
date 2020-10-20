clear all;
ftp_succ = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;];
stm_succ = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;1;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;];
vop_succ = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;];

ftp_remo_succ = [0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;];
stm_remo_succ = [0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;];
vop_remo_succ = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;1;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;];

service = [1;2;1;1;2;1;2;0;0;1;2;0;2;2;2;1;1;0;1;0;2;1;1;0;2;0;1;1;0;0;0;0;1;1;0;2;1;0;2;1;1;2;1;0;2;1;2;0;0;0;2;1;1;1;2;1;0;1;0;0;0;1;2;2;0;1;0;2;2;2;2;0;1;0;0;1;0;1;1;2;0;0;1;2;0;0;0;1;2;1;0;0;2;0;1;2;0;1;0;0;];

%total失敗率 只要有等待一秒代表失敗

% ftp = size(find(service==1))
% stm = size(find(service==2))
% vop = size(find(service==0))
% 
% 
% ftp__succ = size(find(ftp_succ==1))
% stm__succ = size(find(stm_succ==1))
% vop__succ = size(find(vop_succ==1))
% 
% a = ftp__succ / ftp * 100
% b = stm__succ / stm * 100
% c = vop__succ / vop * 100
% 
% 
% ftp__remo_succ = size(find(ftp_remo_succ==1)) 
% stm__remo_succ = size(find(stm_remo_succ==1))
% vop__remo_succ = size(find(vop_remo_succ==1))
% 
% d = ftp__remo_succ / ftp * 100
% e = stm__remo_succ / stm * 100
% f = vop__remo_succ / vop * 100


size(find(ftp_succ==1))/(size(find(service==1))) * 100
size(find(stm_succ==1))/(size(find(service==2))) * 100
size(find(vop_succ==1))/(size(find(service==0))) * 100

size(find(ftp_remo_succ==1))/(size(find(service==1))) * 100
size(find(stm_remo_succ==1))/(size(find(service==2))) * 100
size(find(vop_remo_succ==1))/(size(find(service==0))) * 100


% 



%移動平均
% for i=3:100
%     total=size(find(ftp_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1) / 3;
% end

% for i=3:100
%     total=size(find(vop_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1) / 3;
% end

% for i=3:100
%     total=size(find(stm_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1) / 3;
% end


% for i=3:100
%     total=size(find(ftp_remo_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1) / 3;
% end

% for i=3:100
%     total=size(find(vop_remo_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1) / 3;
% end

%****************************************************************
% figure;
% for i=3:100
%     total=size(find(stm_remo_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1)/ 3;
% end
% 
% plot(avg_pre)
% plot(1:98, avg_pre, 1:98, stm_remo_succ(1:98))
% title('stm__remo moving avg fail rate');
% xlabel('stm__remo packet');
% ylabel('rate');
% 
% 
% 
% figure;
% for i=3:100
%     total=size(find(stm_succ(i-2:i)==1));
%     avg_pre(i-2)=total(:,1)/ 3;
% end
% 
% plot(avg_pre)
% plot(1:98, avg_pre, 1:98, stm_succ(1:98))
% title('stm moving avg fail rate');
% xlabel('stm packet');
% ylabel('rate');
%****************************************************************
figure;
for i=5:100
    total=size(find(stm_remo_succ(i-4:i)==1));
    avg_pre(i-4)=total(:,1)/ 5;
end

plot(avg_pre)
plot(1:96, avg_pre, 1:96, stm_remo_succ(1:96))
title('stm 無機制移動平均失敗率');
xlabel('封包');
ylabel('失敗率');



figure;
for i=5:100
    total=size(find(stm_succ(i-4:i)==1));
    avg_pre(i-4)=total(:,1)/ 5;
end

plot(avg_pre)
plot(1:96, avg_pre, 1:96, stm_succ(1:96))
title('stm 有機制移動平均失敗率');
xlabel('封包');
ylabel('失敗率');