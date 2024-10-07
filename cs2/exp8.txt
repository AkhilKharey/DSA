clearvars; clc;

% Simulation parameters
nSymm = 10^4; 
EbN0dB = 0:2:20; 
MOD_TYPE = 'MPSK'; 
M = 64; 
N = 64; 
Ncp = 16; 

% Derived Parameters
k = log2(M);
EsN0dB = 10*log10(k) + EbN0dB;
errors = zeros(1, length(EsN0dB));

% Monte Carlo Simulation
for i = 1:length(EsN0dB)
    for j = 1:nSymm

        % Transmitter
        d = ceil(M .* rand(1, N)); 
        [X, ref] = modulation_mapper(MOD_TYPE, M, d); 
        x = ifft(X, N); % IDFT
        s = add_cyclic_prefix(x, Ncp); 

        % Channel
        r = add_awgn_noise(s, EsN0dB(i)); 

        % Receiver
        y = remove_cyclic_prefix(r, Ncp, N); 
        Y = fft(y, N); % DFT
        [~, dcap] = iqoptDetector(Y, ref); 

        % Error counter
        d = d(:).'; 
        dcap = dcap(:).';  
        numErrors = sum(d ~= dcap); 
        errors(i) = errors(i) + numErrors; 
    end
end

simulatedSER = errors / (nSymm * N);

theoreticalSER = ser_awgn(EbN0dB, MOD_TYPE, M);

% Plot theoretical curves and simulated BER points
plot(EbN0dB, log10(simulatedSER), 'ro'); hold on;
plot(EbN0dB, log10(theoreticalSER), 'r'); grid on;
title(['Performance of ', num2str(M), ' ', MOD_TYPE, ' OFDM over AWGN channel']);
xlabel('Eb/N0 (dB)');
ylabel('Symbol Error Rate');
legend('simulated', 'theoretical');                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     