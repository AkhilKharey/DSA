clear all;

nFFT = 64; nDSC = 52; nSym = 10^4; EbN0dB = 0:10;
EsN0dB = EbN0dB + 10*log10(nDSC/nFFT) + 10*log10(64/80);
nBitPerSym = 52;

for ii = 1:length(EbN0dB)
    % Transmitter
    ipBit = rand(1, nBitPerSym * nSym) > 0.5; % Random bits
    ipMod = 2 * ipBit - 1; % BPSK modulation
    ipMod = reshape(ipMod, nBitPerSym, nSym).'; % Symbols
    
    % Assigning to subcarriers
    xF = [zeros(nSym, 6), ipMod(:,1:nBitPerSym/2), zeros(nSym, 1), ipMod(:,nBitPerSym/2+1:end), zeros(nSym, 5)];
    
    % IFFT, cyclic prefix
    xt = (nFFT/sqrt(nDSC)) * ifft(fftshift(xF.')).';
    xt = [xt(:,49:64) xt];
    xt = reshape(xt.', 1, nSym * 80);
    
    % Add noise
    nt = (randn(1, nSym * 80) + 1j * randn(1, nSym * 80)) / sqrt(2);
    yt = sqrt(80/64) * xt + 10^(-EsN0dB(ii)/20) * nt;
    
    % Receiver
    yt = reshape(yt.', 80, nSym).'; yt = yt(:,17:80); % Remove CP
    yF = (sqrt(nDSC)/nFFT) * fftshift(fft(yt.')).';
    yMod = yF(:, [6+(1:nBitPerSym/2), 7+(nBitPerSym/2+1:nBitPerSym)]);
    
    % BPSK demodulation
    ipModHat = 2 * (real(yMod) > 0) - 1;
    ipBitHat = (ipModHat + 1) / 2;
    ipBitHat = reshape(ipBitHat.', nBitPerSym * nSym, 1).';
    
    % Error counting
    nErr(ii) = sum(ipBitHat ~= ipBit);
end

% BER calculation & plotting
simBer = nErr / (nSym * nBitPerSym);
theoryBer = (1/2) * erfc(sqrt(10.^(EbN0dB/10)));
figure;
semilogy(EbN0dB, theoryBer, 'bs-', EbN0dB, simBer, 'mx-');
axis([0 10 1e-5 1]); grid on;
legend('Theory', 'Simulation');
xlabel('Eb/No (dB)'); ylabel('BER');
title('BPSK-OFDM Bit Error Probability');
