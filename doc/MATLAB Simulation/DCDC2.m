function DCDC2()
%DCDC simulates the dc-dc equation, by 
%   using the decision function "DCDCIsAcceptable"

A1 = [1 0; 0 0.9702];

B1 = [0.2; 0];

A2 = [0.988 -0.1308; 0.1784 0.9583];

B2 = [0.1992; 0.018];

A = {A1, A2};
B = {B1, B2};

X = [1.5; 3.3];

Q = 2;
T = 1000;

Trace = zeros(2, T+1);
TraceWODrift(:,1) = X;
draw();
hold on;
s = 1;
for i=1:T
    
    drift = driftGen(2) * 0.001;
    X = X + drift(:,randi([1 2])) * 0.99;
    Trace(:,i) = X;
    Xj = A{s} * X + B{s};
    valids = {};
    numOfValids = 0;
    if IsInDisturbanceInvariant(Xj) == 0
        numOfValids = 1;
        valids{1} = s;
    else
        for j=Q:-1:1
            Xj = A{j} * X + B{j};
            if IsInDisturbanceInvariant(Xj) == 0
                numOfValids = numOfValids+1;
                valids{numOfValids} = j;
                break;
            end
        end
    end
    if numOfValids == 0
        disp('error');
        return;
    end
    s = valids{randi([1 numOfValids])};
    X = A{s} * X + B{s};
    TraceWODrift(:, i+1) = X;
end
scatter(Trace(1,1:T-1), Trace(2,1:T-1));

end

function output = driftGen( numOfDimensions )
%DRIFTGENERATOR Summary of this function goes here
%   Detailed explanation goes here

if (numOfDimensions == 1)
    output = [0 1];
    return;
end

left = ones(1, 2^(numOfDimensions-1)) * 0;
right= ones(1, 2^(numOfDimensions-1)) * 1;
output = [ left right; 
    driftGen(numOfDimensions-1) driftGen(numOfDimensions-1)
    ];

end
