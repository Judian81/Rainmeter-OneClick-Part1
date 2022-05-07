
function Initialize() 
	swapStringNum = '%^1%^'
end

function Update() end

function Make(nStcks)

	MeterMeasures(nStcks)
	MakeString( nStcks, 'InvestCalcString', 'cInvestment' )
	MakeString( nStcks, 'DailyCalcString', 'cDayLossGain' )	
	MakeString( nStcks, 'OverallCalcString', 'cGainLoss' )
	SKIN:Bang('!Refresh')

end -- function Make

function MeterMeasures(nStks)
  local rTable = {}
  local lines = {} 
  
	for line in io.lines(SELF:GetOption('templateFile')) do
		table.insert(rTable, line)
	end 
	for k = 2, nStks do
		for l,line in pairs(rTable) do		
			line = line:gsub(swapStringNum, k)
			table.insert(lines, line)
		end
	end
	outputFile = io.open(SELF:GetOption('outputFile'), 'w')
	outputFile:write(table.concat(lines, '\n'))
	outputFile:close()	
	
end -- function MeterMeasures

function MakeString(nStks, sName, cVal)
	local calcStr = '('
  
	for k = 1, nStks do 
		calcStr = calcStr..' + '..cVal..k..'' 	
	end
	calcStr = calcStr..')'
	SKIN:Bang('!WriteKeyValue Variables "'..sName..'" "'..calcStr..'"')	
	
end -- function CalcStrings