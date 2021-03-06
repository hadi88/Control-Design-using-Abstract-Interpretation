function [ result ] = IsInDisturbanceInvariant( X )
if ( ~(-2*X(1) + 0*X(2) >= -5) || ~(0*X(1) + -100*X(2) >= -363) || ~(0*X(1) + 100*X(2) >= 297) || ~(1*X(1) + 0*X(2) >= -0) ) 
	result = 1;
	return;
end
if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 && 12350*X(1) + -1635*X(2) >= -2476 ) 
	if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 ) 
		if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 && 0*X(1) + 100*X(2) >= 297 ) 
			if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 && 0*X(1) + 100*X(2) >= 297 ) 
				if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -1.18911e+08*X(1) + -9.35938e+07*X(2) >= -5.01895e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 && 0*X(1) + 100*X(2) >= 297 ) 
					if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && 3.35455e+08*X(1) + 1.85344e+08*X(2) >= 9.39025e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 && -3.01487e+07*X(1) + 3.07437e+07*X(2) >  5.04191e+07 && 0*X(1) + 100*X(2) >= 297 ) 
						if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && 0*X(1) + 980*X(2) >= 3001 && -3.01487e+07*X(1) + 3.07437e+07*X(2) >  5.04191e+07 ) 
							if ( -1000*X(1) + -1000*X(2) >  -4371 && -1000*X(1) + 0*X(2) >  -1261 && -500*X(1) + 500*X(2) >  901 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 125*X(1) + 125*X(2) >  522 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 && 1000*X(1) + -1000*X(2) >  -1969 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -3.01487e+07*X(1) + 3.07437e+07*X(2) >  5.04191e+07 && -500*X(1) + -500*X(2) >  -2237 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 1000*X(1) + -1000*X(2) >  -1947 && 3.35455e+08*X(1) + 1.85344e+08*X(2) >= 9.39025e+08 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -1.18911e+08*X(1) + -9.35938e+07*X(2) >= -5.01895e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && 3.35455e+08*X(1) + 1.85344e+08*X(2) >= 9.39025e+08 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 && 0*X(1) + 100*X(2) >= 297 ) 
							if ( -500*X(1) + -500*X(2) >  -2219 && -125*X(1) + 0*X(2) >  -182 && 0*X(1) + -40*X(2) >  -121 && 0*X(1) + 100*X(2) >= 297 && 40*X(1) + 40*X(2) >  173 && 500*X(1) + -500*X(2) >  -807 && 3.01488e+07*X(1) + -3.07436e+07*X(2) >= -5.04190e+07 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -3.35454e+08*X(1) + -1.85343e+08*X(2) >  -9.39024e+08 && -1000*X(1) + -1000*X(2) >  -4167 && -100*X(1) + 100*X(2) >  181 && 0*X(1) + 100*X(2) >= 297 && 500*X(1) + -500*X(2) >  -973 && 1.41738e+08*X(1) + -1.08979e+08*X(2) >= -1.75647e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				else
					if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -1.18911e+08*X(1) + -9.35938e+07*X(2) >= -5.01895e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 && 5.94558e+07*X(1) + 4.6797e+07*X(2) >= 2.00387e+08 && 0*X(1) + 100*X(2) >= 297 ) 
						if ( 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 && -1.41737e+08*X(1) + 1.0898e+08*X(2) >  1.75648e+08 && 5.94558e+07*X(1) + 4.6797e+07*X(2) >= 2.00387e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 0*X(1) + 980*X(2) >= 3001 ) 
							if ( 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 && -1.41737e+08*X(1) + 1.0898e+08*X(2) >  1.75648e+08 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 ) 
								if ( -1000*X(1) + -1000*X(2) >  -4271 && -125*X(1) + 0*X(2) >  -133 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 ) 
									result = 1;
								else
									result = 0;
								end
							else
								if ( -1.41737e+08*X(1) + 1.0898e+08*X(2) >  1.75648e+08 && -500*X(1) + -500*X(2) >  -2173 && -200*X(1) + 200*X(2) >  389 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 125*X(1) + -125*X(2) >  -282 && 500*X(1) + 0*X(2) >  447 && 5.94558e+07*X(1) + 4.6797e+07*X(2) >= 2.00387e+08 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 ) 
									result = 1;
								else
									result = 0;
								end
							end
						else
							if ( -1.41737e+08*X(1) + 1.0898e+08*X(2) >  1.75648e+08 && -250*X(1) + 0*X(2) >  -279 && -250*X(1) + 250*X(2) >  481 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 5.94558e+07*X(1) + 4.6797e+07*X(2) >= 2.00387e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 && 0*X(1) + 980*X(2) >= 3001 && -5.94557e+07*X(1) + -4.67969e+07*X(2) >  -2.00386e+08 ) 
							if ( -5.94557e+07*X(1) + -4.67969e+07*X(2) >  -2.00386e+08 && -25*X(1) + -25*X(2) >  -101 && 0*X(1) + 980*X(2) >= 3001 && 4*X(1) + -4*X(2) >  -9 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -5.94557e+07*X(1) + -4.67969e+07*X(2) >  -2.00386e+08 && -1000*X(1) + -1000*X(2) >  -4023 && -125*X(1) + 125*X(2) >  242 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 200*X(1) + -200*X(2) >  -443 && 200*X(1) + 0*X(2) >  167 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 && 5.12158e+08*X(1) + -2.94005e+08*X(2) >= -4.66144e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				end
			else
				if ( -1.60399e+08*X(1) + -1.78159e+08*X(2) >= -8.38531e+08 && -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 && 0*X(1) + 100*X(2) >= 297 ) 
					if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 ) 
						if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 ) 
							if ( -1000*X(1) + 0*X(2) >  -867 && -500*X(1) + -500*X(2) >  -2087 && -250*X(1) + 250*X(2) >  597 && 0*X(1) + -1.24301e+08*X(2) >  -4.17190e+08 && 0*X(1) + -1000*X(2) >  -3357 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 125*X(1) + 0*X(2) >  87 && 500*X(1) + -500*X(2) >  -1309 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && -500*X(1) + -500*X(2) >  -2107 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 50*X(1) + 50*X(2) >  193 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + 980*X(2) >= 3001 ) 
							if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && -50*X(1) + -50*X(2) >  -203 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 20*X(1) + -20*X(2) >  -49 && 125*X(1) + 125*X(2) >  483 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -5.12157e+08*X(1) + 2.94006e+08*X(2) >  4.66145e+08 && -125*X(1) + 0*X(2) >  -106 && -100*X(1) + -100*X(2) >  -391 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 25*X(2) >  76 && 250*X(1) + 0*X(2) >  203 && 2.005e+07*X(1) + 2.227e+07*X(2) >= 8.4507e+07 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				else
					if ( 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 && 0*X(1) + 980*X(2) >= 3001 && -2.00499e+07*X(1) + -2.22699e+07*X(2) >  -8.45069e+07 ) 
						if ( 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && -2.00499e+07*X(1) + -2.22699e+07*X(2) >  -8.45069e+07 ) 
							if ( -2.00499e+07*X(1) + -2.22699e+07*X(2) >  -8.45069e+07 && -500*X(1) + -500*X(2) >  -1933 && -250*X(1) + 0*X(2) >  -177 && 0*X(1) + -1000*X(2) >  -3191 && 0*X(1) + 250*X(2) >  789 && 200*X(1) + 0*X(2) >  131 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -2.00499e+07*X(1) + -2.22699e+07*X(2) >  -8.45069e+07 && -250*X(1) + -250*X(2) >  -969 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 125*X(1) + 0*X(2) >  78 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -2.00499e+07*X(1) + -2.22699e+07*X(2) >  -8.45069e+07 && -500*X(1) + -500*X(2) >  -1943 && -250*X(1) + 0*X(2) >  -229 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 200*X(1) + 0*X(2) >  131 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			end
		else
			if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 ) 
				if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 1.11995e+09*X(1) + -4.60734e+08*X(2) >= -7.19100e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 && 0*X(1) + 100*X(2) >= 297 ) 
					if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && 1.604e+08*X(1) + 1.7816e+08*X(2) >  8.38532e+08 && 0*X(1) + 980*X(2) >= 3001 ) 
						if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -500*X(1) + -500*X(2) >  -2509 && -250*X(1) + 0*X(2) >  -489 && 0*X(1) + -1000*X(2) >  -3119 && 0*X(1) + 980*X(2) >= 3001 && 125*X(1) + -125*X(2) >  -157 && 250*X(1) + 250*X(2) >  1231 && 1000*X(1) + 0*X(2) >  1853 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >= -3.47024e+08 && -40*X(1) + -40*X(2) >  -203 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 500*X(1) + 0*X(2) >  931 && 1000*X(1) + -1000*X(2) >  -1199 && 1.604e+08*X(1) + 1.7816e+08*X(2) >  8.38532e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + -100*X(2) >= -363 ) 
							if ( -1000*X(1) + -1000*X(2) >  -4081 && -100*X(1) + 0*X(2) >  -67 && 0*X(1) + -1.20597e+08*X(2) >  -4.17310e+08 && 0*X(1) + -1000*X(2) >  -3461 && 0*X(1) + 200*X(2) >  671 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && 200*X(1) + 0*X(2) >  97 && 1000*X(1) + -1000*X(2) >  -2947 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && -200*X(1) + -200*X(2) >  -819 && 0*X(1) + -1.24301e+08*X(2) >  -4.17190e+08 && 0*X(1) + -1000*X(2) >  -3357 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 500*X(1) + 0*X(2) >  229 && 1000*X(1) + -1000*X(2) >  -2871 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 0*X(1) + -100*X(2) >= -363 ) 
							if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 250*X(1) + 250*X(2) >  909 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -1.11994e+09*X(1) + 4.60735e+08*X(2) >  7.19101e+08 && -200*X(1) + -200*X(2) >  -763 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 25*X(2) >  77 && 500*X(1) + -500*X(2) >  -1327 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >= 2.81764e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				end
			else
				if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >  -2.81763e+08 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 && 0*X(1) + 980*X(2) >= 3001 ) 
					if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >  -2.81763e+08 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 ) 
						if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >  -2.81763e+08 && -125*X(1) + 0*X(2) >  -63 && 0*X(1) + -200*X(2) >  -639 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 125*X(1) + -125*X(2) >  -344 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >  -2.81763e+08 && -25*X(1) + -25*X(2) >  -93 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 40*X(1) + -40*X(2) >  -109 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -5.02722e+07*X(1) + -8.12266e+07*X(2) >  -2.81763e+08 && -1000*X(1) + -1000*X(2) >  -3777 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 250*X(1) + 250*X(2) >  881 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		end
	else
		if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 5.95506e+08*X(1) + -1.59110e+08*X(2) >= -2.44579e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 ) 
			if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && -50000*X(1) + 0*X(2) >= -104849 && 0*X(1) + 980*X(2) >= 3001 ) 
				if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 ) 
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 ) 
						if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 ) 
							if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -250*X(1) + -250*X(2) >  -1253 && -200*X(1) + 0*X(2) >  -339 && 0*X(1) + -50*X(2) >  -167 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 125*X(1) + 125*X(2) >  616 && 1000*X(1) + -1000*X(2) >  -1703 && 1000*X(1) + 0*X(2) >  1631 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -1000*X(1) + 0*X(2) >  -1853 && 0*X(1) + -1000*X(2) >  -3317 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 20*X(1) + 20*X(2) >  99 && 500*X(1) + -500*X(2) >  -811 && 5e+08*X(1) + 0*X(2) >  8.4749e+08 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -125*X(1) + 0*X(2) >  -237 && -50*X(1) + 50*X(2) >  63 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 500*X(1) + 0*X(2) >  837 && 500*X(1) + 500*X(2) >  2459 && 1000*X(1) + -1000*X(2) >  -1581 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && -50000*X(1) + 0*X(2) >= -104849 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 ) 
						if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -50000*X(1) + 0*X(2) >= -104849 && -1000*X(1) + 0*X(2) >  -2097 && -500*X(1) + -500*X(2) >  -2629 && 0*X(1) + -1000*X(2) >  -3239 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 250*X(1) + 250*X(2) >  1263 && 500*X(1) + 0*X(2) >  947 && 1000*X(1) + -1000*X(2) >  -1343 && 5e+06*X(1) + 0*X(2) >  9.4799e+06 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -50000*X(1) + 0*X(2) >= -104849 && -1000*X(1) + 0*X(2) >  -2097 && -250*X(1) + 250*X(2) >  241 && -200*X(1) + -200*X(2) >  -1051 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 5*X(1) + 0*X(2) >  9 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			else
				if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + 100*X(2) >= 297 ) 
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 && -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + 980*X(2) >= 3001 ) 
						if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -1000*X(1) + -1000*X(2) >  -5381 && -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + 980*X(2) >= 3001 && 125*X(1) + -125*X(2) >  -133 && 200*X(1) + 0*X(2) >  419 && 50000*X(1) + 0*X(2) >  104849 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 125*X(1) + 125*X(2) >  627 && 5.02723e+07*X(1) + 8.12267e+07*X(2) >  3.47025e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -200*X(1) + -200*X(2) >  -1101 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + 100*X(2) >= 297 && 200*X(1) + -200*X(2) >  -157 && 500*X(1) + 0*X(2) >  1149 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		else
			if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >= -3.55683e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 && 12350*X(1) + -1635*X(2) >= -2476 ) 
				if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 0*X(1) + -100*X(2) >= -363 ) 
					if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && 0*X(1) + -100*X(2) >= -363 ) 
							if ( -250*X(1) + 0*X(2) >  -69 && -50*X(1) + -50*X(2) >  -193 && 0*X(1) + -200*X(2) >  -717 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && 100*X(1) + 0*X(2) >  27 && 12350*X(1) + -1635*X(2) >= -2476 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -1000*X(1) + -1000*X(2) >  -3991 && -1000*X(1) + 0*X(2) >  -473 && 0*X(1) + -5.85018e+07*X(2) >  -2.08713e+08 && 0*X(1) + -125*X(2) >  -446 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && 125*X(1) + -125*X(2) >  -412 && 125*X(1) + 0*X(2) >  32 && 12350*X(1) + -1635*X(2) >= -2476 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && 0*X(1) + -100*X(2) >= -363 ) 
							if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && -40*X(1) + -40*X(2) >  -159 && 0*X(1) + -1.20597e+08*X(2) >  -4.17310e+08 && 0*X(1) + -1000*X(2) >  -3461 && 0*X(1) + 200*X(2) >  671 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 1000*X(1) + -1000*X(2) >  -3203 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && -1000*X(1) + -1000*X(2) >  -3843 && -200*X(1) + 200*X(2) >  559 && 0*X(1) + -1.24301e+08*X(2) >  -4.17190e+08 && 0*X(1) + -1000*X(2) >  -3357 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 250*X(1) + 250*X(2) >  871 && 1000*X(1) + -1000*X(2) >  -3113 && 12350*X(1) + -1635*X(2) >= -2476 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				else
					if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && -50*X(1) + 0*X(2) >  -23 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 40*X(1) + -40*X(2) >  -121 && 125*X(1) + 0*X(2) >  27 && 12350*X(1) + -1635*X(2) >= -2476 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -5.95505e+08*X(1) + 1.59111e+08*X(2) >  2.4458e+08 && -1000*X(1) + 0*X(2) >  -433 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >= 2.9016e+08 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 25*X(2) >  77 && 50*X(1) + -50*X(2) >  -147 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			else
				if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >  -2.90159e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 980*X(2) >= 3001 ) 
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >  -2.90159e+08 && 12350*X(1) + -1635*X(2) >= -2476 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 ) 
						if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >  -2.90159e+08 && -125*X(1) + -125*X(2) >  -422 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 12350*X(1) + -1635*X(2) >= -2476 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >  -2.90159e+08 && -125*X(1) + 0*X(2) >  -58 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + 980*X(2) >= 3001 && 50*X(1) + -50*X(2) >  -147 && 500*X(1) + 500*X(2) >  1633 && 12350*X(1) + -1635*X(2) >= -2476 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -3.47219e+07*X(1) + -8.95004e+07*X(2) >  -2.90159e+08 && -125*X(1) + -125*X(2) >  -459 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 200*X(1) + 200*X(2) >  649 && 500*X(1) + -500*X(2) >  -1429 && 12350*X(1) + -1635*X(2) >= -2476 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		end
	end
else
	if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 1*X(1) + 0*X(2) >= -0 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 ) 
		if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 && 12350*X(1) + -1635*X(2) >= -2476 ) 
			if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
				if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 ) 
					if ( 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 ) 
						if ( 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 ) 
							if ( -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -500*X(1) + 0*X(2) >  -747 && -200*X(1) + 200*X(2) >  393 && -125*X(1) + -125*X(2) >  -623 && 0*X(1) + -1000*X(2) >  -3511 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && 500*X(1) + 0*X(2) >  691 && 500*X(1) + 500*X(2) >  2439 && 1000*X(1) + -1000*X(2) >  -2127 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && -500*X(1) + 0*X(2) >  -747 && -200*X(1) + -200*X(2) >  -991 && -10*X(1) + 10*X(2) >  19 && 0*X(1) + -1.20597e+08*X(2) >  -4.17310e+08 && 0*X(1) + -1000*X(2) >  -3461 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && 200*X(1) + 0*X(2) >  283 && 250*X(1) + -250*X(2) >  -511 && 250*X(1) + 250*X(2) >  1217 ) 
								result = 1;
							else
								result = 0;
							end
						end
					else
						if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 ) 
							if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -200*X(1) + 0*X(2) >  -339 && -50*X(1) + 50*X(2) >  83 && 0*X(1) + -100*X(2) >  -349 && 0*X(1) + 200*X(2) >  671 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && 125*X(1) + 125*X(2) >  611 && 250*X(1) + 0*X(2) >  373 && 2.5e+08*X(1) + 0*X(2) >  3.73495e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
								result = 1;
							else
								result = 0;
							end
						else
							if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && -200*X(1) + 0*X(2) >  -339 && -50*X(1) + 50*X(2) >  81 && 0*X(1) + -1.24301e+08*X(2) >  -4.17190e+08 && 0*X(1) + -1000*X(2) >  -3357 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && 250*X(1) + -250*X(2) >  -441 ) 
								result = 1;
							else
								result = 0;
							end
						end
					end
				else
					if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 ) 
						if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -125*X(1) + -125*X(2) >  -664 && -125*X(1) + 0*X(2) >  -237 && 0*X(1) + -1000*X(2) >  -3453 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 100*X(1) + 100*X(2) >  501 && 500*X(1) + -500*X(2) >  -879 && 5e+08*X(1) + 0*X(2) >  8.4749e+08 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -125*X(1) + 0*X(2) >  -237 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			else
				if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -500*X(1) + 0*X(2) >= -1149 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
					if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -50000*X(1) + 0*X(2) >= -104849 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
						if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -50000*X(1) + 0*X(2) >= -104849 && -1000*X(1) + 0*X(2) >  -2097 && -40*X(1) + -40*X(2) >  -219 && 0*X(1) + -125*X(2) >  -427 && 25*X(1) + -25*X(2) >  -38 && 500*X(1) + 0*X(2) >  947 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 && 5e+06*X(1) + 0*X(2) >  9.4799e+06 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -1000*X(1) + -1000*X(2) >  -5639 && -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + -500*X(2) >  -1689 && 125*X(1) + 125*X(2) >  657 && 200*X(1) + 0*X(2) >  419 && 50000*X(1) + 0*X(2) >  104849 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -1000*X(1) + -1000*X(2) >  -5803 && -2*X(1) + 0*X(2) >= -5 && 500*X(1) + 0*X(2) >  1149 && 3.4722e+07*X(1) + 8.95005e+07*X(2) >  3.55684e+08 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		else
			if ( 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && -12350*X(1) + 1635*X(2) >  2476 && 0*X(1) + -100*X(2) >= -363 ) 
				if ( 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && 0*X(1) + -100*X(2) >= -363 && -12350*X(1) + 1635*X(2) >  2476 ) 
					if ( 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && 0*X(1) + -100*X(2) >= -363 && -12350*X(1) + 1635*X(2) >  2476 ) 
						if ( -12350*X(1) + 1635*X(2) >  2476 && -1000*X(1) + -1000*X(2) >  -3903 && -250*X(1) + 0*X(2) >  -69 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 500*X(2) >  1783 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && 1*X(1) + 0*X(2) >= -0 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -12350*X(1) + 1635*X(2) >  2476 && -125*X(1) + 0*X(2) >  -34 && -25*X(1) + -25*X(2) >  -96 && 0*X(1) + -5.85018e+07*X(2) >  -2.08713e+08 && 0*X(1) + -125*X(2) >  -446 && 0*X(1) + 1.20598e+08*X(2) >= 4.17311e+08 && 1*X(1) + 0*X(2) >= -0 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && -12350*X(1) + 1635*X(2) >  2476 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -12350*X(1) + 1635*X(2) >  2476 && -500*X(1) + -500*X(2) >  -1859 && -500*X(1) + 0*X(2) >  -129 && 0*X(1) + -1.20597e+08*X(2) >  -4.17310e+08 && 0*X(1) + -1000*X(2) >  -3461 && 0*X(1) + 200*X(2) >  671 && 0*X(1) + 1.24302e+08*X(2) >= 4.17191e+08 && 1*X(1) + 0*X(2) >= -0 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -12350*X(1) + 1635*X(2) >  2476 && -250*X(1) + 0*X(2) >  -61 && 0*X(1) + -1.24301e+08*X(2) >  -4.17190e+08 && 0*X(1) + -1000*X(2) >  -3357 && 0*X(1) + 500*X(2) >  1627 && 0*X(1) + 2.30616e+08*X(2) >= 7.50719e+08 && 1*X(1) + 0*X(2) >= -0 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			else
				if ( 178400*X(1) + 958300*X(2) >= 2.95314e+06 && -12350*X(1) + 1635*X(2) >  2476 && 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 980*X(2) >= 3001 && 0*X(1) + -100*X(2) >= -363 ) 
					if ( 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && -12350*X(1) + 1635*X(2) >  2476 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -12350*X(1) + 1635*X(2) >  2476 && 0*X(1) + -2.30615e+08*X(2) >  -7.50718e+08 && 0*X(1) + -125*X(2) >  -407 && 0*X(1) + 250*X(2) >  789 && 0*X(1) + 2.37699e+06*X(2) >= 7.50488e+06 && 1*X(1) + 0*X(2) >= -0 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -12350*X(1) + 1635*X(2) >  2476 && -125*X(1) + 125*X(2) >  357 && -8*X(1) + -8*X(2) >  -27 && 0*X(1) + -2.37699e+06*X(2) >  -7.50487e+06 && 0*X(1) + -500*X(2) >  -1579 && 0*X(1) + 980*X(2) >= 3001 && 1*X(1) + 0*X(2) >= -0 && 25*X(1) + 25*X(2) >  77 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( -12350*X(1) + 1635*X(2) >  2476 && 0*X(1) + -980*X(2) >  -3001 && 178400*X(1) + 958300*X(2) >= 2.95314e+06 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		end
	else
		if ( -50000*X(1) + 0*X(2) >= -104849 && 178400*X(1) + 958300*X(2) >  3.61087e+06 && 0*X(1) + -100*X(2) >= -363 ) 
			if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && 178400*X(1) + 958300*X(2) >  3.61087e+06 && 0*X(1) + -100*X(2) >= -363 ) 
				if ( 178400*X(1) + 958300*X(2) >  3.61087e+06 && -6.25e+07*X(1) + 0*X(2) >= -8.08112e+07 && 0*X(1) + -100*X(2) >= -363 ) 
					if ( 178400*X(1) + 958300*X(2) >  3.61087e+06 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && -6.25e+07*X(1) + 0*X(2) >= -8.08112e+07 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -6.25e+07*X(1) + 0*X(2) >= -8.08112e+07 && -1000*X(1) + 0*X(2) >  -1293 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 500*X(2) >  1783 && 0*X(1) + 5.85019e+07*X(2) >= 2.08714e+08 && 25*X(1) + -25*X(2) >  -63 && 1000*X(1) + 1000*X(2) >  4739 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -6.25e+07*X(1) + 0*X(2) >= -8.08112e+07 && -1000*X(1) + 0*X(2) >  -1293 && 0*X(1) + -5.85018e+07*X(2) >  -2.08713e+08 && 0*X(1) + -125*X(2) >  -446 && 0*X(1) + 500*X(2) >  1763 && 1000*X(1) + -1000*X(2) >  -2357 && 1000*X(1) + 0*X(2) >  1209 && 1000*X(1) + 1000*X(2) >  4769 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
							result = 1;
						else
							result = 0;
						end
					end
				else
					if ( 178400*X(1) + 958300*X(2) >  3.61087e+06 && -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && 0*X(1) + -100*X(2) >= -363 ) 
						if ( -2.5e+08*X(1) + 0*X(2) >= -3.73494e+08 && -500*X(1) + 0*X(2) >  -747 && -250*X(1) + -250*X(2) >  -1281 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 125*X(2) >  436 && 500*X(1) + -500*X(2) >  -1169 && 6.25e+07*X(1) + 0*X(2) >  8.08113e+07 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
							result = 1;
						else
							result = 0;
						end
					else
						if ( -5e+08*X(1) + 0*X(2) >= -8.47489e+08 && -200*X(1) + 0*X(2) >  -339 && -40*X(1) + -40*X(2) >  -213 && 0*X(1) + -100*X(2) >= -363 && 250*X(1) + 0*X(2) >  373 && 2.5e+08*X(1) + 0*X(2) >  3.73495e+08 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
							result = 1;
						else
							result = 0;
						end
					end
				end
			else
				if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && 178400*X(1) + 958300*X(2) >  3.61087e+06 && 0*X(1) + -100*X(2) >= -363 ) 
					if ( -5e+06*X(1) + 0*X(2) >= -9.47989e+06 && -125*X(1) + 0*X(2) >  -237 && 0*X(1) + -100*X(2) >= -363 && 125*X(1) + -125*X(2) >  -242 && 500*X(1) + 500*X(2) >  2573 && 5e+08*X(1) + 0*X(2) >  8.4749e+08 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
						result = 1;
					else
						result = 0;
					end
				else
					if ( -50000*X(1) + 0*X(2) >= -104849 && -1000*X(1) + 0*X(2) >  -2097 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 125*X(2) >  422 && 100*X(1) + 100*X(2) >  531 && 200*X(1) + -200*X(2) >  -347 && 500*X(1) + 0*X(2) >  947 && 178400*X(1) + 958300*X(2) >  3.61087e+06 && 5e+06*X(1) + 0*X(2) >  9.4799e+06 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		else
			if ( -178400*X(1) + -958300*X(2) >= -3.61086e+06 && -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 0*X(1) + 100*X(2) >= 297 && 1*X(1) + 0*X(2) >= -0 ) 
				if ( -178400*X(1) + -958300*X(2) >  -2.95313e+06 && 1*X(1) + 0*X(2) >= -0 && 0*X(1) + 980*X(2) >= 3001 ) 
					if ( -178400*X(1) + -958300*X(2) >  -2.95313e+06 && 0*X(1) + 980*X(2) >= 3001 && 1*X(1) + 0*X(2) >= -0 ) 
						result = 1;
					else
						result = 0;
					end
				else
					if ( -178400*X(1) + -958300*X(2) >  -2.95313e+06 && 0*X(1) + -980*X(2) >  -3001 && 0*X(1) + 100*X(2) >= 297 && 1*X(1) + 0*X(2) >= -0 ) 
						result = 1;
					else
						result = 0;
					end
				end
			else
				if ( -500*X(1) + 0*X(2) >= -1149 && 178400*X(1) + 958300*X(2) >  3.61087e+06 && 0*X(1) + -100*X(2) >= -363 ) 
					if ( -500*X(1) + 0*X(2) >= -1149 && 0*X(1) + -100*X(2) >= -363 && 200*X(1) + 0*X(2) >  419 && 50000*X(1) + 0*X(2) >  104849 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
						result = 1;
					else
						result = 0;
					end
				else
					if ( -2*X(1) + 0*X(2) >= -5 && 0*X(1) + -100*X(2) >= -363 && 500*X(1) + 0*X(2) >  1149 && 178400*X(1) + 958300*X(2) >  3.61087e+06 ) 
						result = 1;
					else
						result = 0;
					end
				end
			end
		end
	end
end
end
