% Y=[10 13 40 50];%產生Y向量值
% subplot(2,2,1), pie3(Y)
% title('1.未加任何標示');
% subplot(2,2,2), pie3(Y,[0 0 0 1]) 
% title('2.第四部產生爆炸');
% subplot(2,2,3), pie3(Y,{'東部','西部','南部','北部'})  
% title('3.設定各組名稱'); 
% subplot(2,2,4), pie3(Y,[0 0 1 1],{'東部','西部','南部','北部'})  
% title('4.設定名稱及南北部爆炸'); 

% x = [1 3 0.5 2.5 2];
% explode = [0 1 0 0 0];
% pie3(x,explode)
% colormap jet

% x = [1 3 0.5 2.5 2];
% explode = [0 1 0 0 0];
% pie3(x,explode)
% colormap hsv

%本論文
%ftp
x = [91.43, 8.57];
explode = [0 1];
label = {'成功率91%','失敗率9%'};
subplot(3,2,1)
pie3(x, explode, label)
% pie3(x, explode)
title('ftp無機制');
colormap jet

x = [100, 0];
explode = [0 1];
label = {'成功率100%','失敗率0%'};
subplot(3,2,2)
pie3(x, explode, label)
% pie3(x, explode)
title('ftp有機制');
colormap jet


%voip
x = [86.84, 13.16];
explode = [0 1];
label = {'成功率87%','失敗率13%'};
subplot(3,2,3)
pie3(x, explode, label)
% pie3(x, explode)
title('voip無機制');
colormap jet

x = [100, 0];
explode = [0 1];
label = {'成功率100%','失敗率0%'};
subplot(3,2,4)
pie3(x, explode, label)
% pie3(x, explode)
title('voip有機制');
colormap jet


%stm
x = [74.07, 25.93];
explode = [0 1];
label = {'成功率74%','失敗率26%'};
subplot(3,2,5)
pie3(x, explode, label)
% pie3(x, explode)
title('stm無機制');
colormap jet

x = [81.48, 18.52];
explode = [0 1];
label = {'成功率81%','失敗率19%'};
subplot(3,2,6)
pie3(x, explode, label)
% pie3(x, explode)
title('stm有機制');
colormap jet
