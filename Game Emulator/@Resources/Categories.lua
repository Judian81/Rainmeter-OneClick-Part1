
function Initialize()

end

function WriteIni(inputtable, filename)
	assert(type(inputtable) == 'table', ('WriteIni must receive a table. Received %s instead.'):format(type(inputtable)))

	local file = assert(io.open(filename, 'w'), 'Unable to open ' .. filename)
	local lines = {}

	for section, contents in pairs(inputtable) do
		table.insert(lines, ('\[%s\]'):format(section))
		for key, value in pairs(contents) do
			table.insert(lines, ('%s=%s'):format(key, value))
		end
		table.insert(lines, '')
	end

	file:write(table.concat(lines, '\r\n'))
	file:close()
end

function ReadIni(inputfile)
	local file = assert(io.open(inputfile, 'r'), 'Unable to open ' .. inputfile)
	local tbl, section = {}
	local num = 0
	for line in file:lines() do
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)'):lower()
				if not tbl[section] then tbl[section] = {} end
			elseif key and command and section then
				tbl[section][key:lower():match('^%s*(%S*)%s*$')] = command:match('^%s*(.-)%s*$')
			elseif #line > 0 and section and not key or command then
				print(num .. ': Invalid property or value.')
			end
		end
	end
	if not section then print('No sections found in ' .. inputfile) end
	file:close()
	return tbl
end

function ReadValues()
	local FileName = SKIN:GetVariable('vCategory')
	FilePath = SKIN:MakePathAbsolute(FileName)
	local file = io.open(FilePath, 'r')
	fLines = {}
		for line in file:lines() do
			table.insert(fLines, line)
		end
	local count = 0
	for line in io.lines(FilePath) do
	   count = count + 1
	end
	file:close()
	cLine = count - 1
	SKIN:Bang('!SetVariable', 'vRomPath', fLines[cLine - 2])
	SKIN:Bang('!SetVariable', 'vEmulatorPath', fLines[cLine - 1])
	SKIN:Bang('!SetVariable', 'vEmulatorName', fLines[cLine])
	SKIN:Bang('!SetVariable', 'vCommandLine', fLines[cLine+1])
end

function GetRoms()
	local FileName = SKIN:GetVariable('vCategory')
	FilePath = SKIN:MakePathAbsolute(FileName)
	local file = io.open(FilePath, 'r')
	fLines = {}
		for line in file:lines() do
			table.insert(fLines, line)
		end
	local count = 0
	for line in io.lines(FilePath) do
	   count = count + 1
	end
	file:close()
	cLine = count - 1
	SKIN:Bang('!SetVariable', 'vRomPath', fLines[cLine - 2])
	--SKIN:Bang('!SetVariable', 'vEmulatorPath', fLines[cLine - 1])
	--SKIN:Bang('!SetVariable', 'vEmulatorName', fLines[cLine])
	--SKIN:Bang('!SetVariable', 'vCommandLine', fLines[cLine+1])
end