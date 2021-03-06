function IntToRoman(int)

    Decimal = {
        _500000 = 0, -- dummy
        _100000 = 0,
        _50000 = 0,
        _10000 = 0,
        _5000 = 0,
        _1000 = 0,
        _500 = 0,
        _100 = 0,
        _50 = 0,
        _10 = 0,
        _5 = 0,
        _1 = 0
    }
    
    Roman = {
        _100000 = 'Č',
        _50000 = 'Ƚ',
        _10000 = 'X̅',
        _5000 = 'V̅',
        _1000 = 'M',
        _500 = 'D',
        _100 = 'C',
        _50 = 'L',
        _10 = 'X',
        _5 = 'V',
        _1 = 'I'
    }

    local str = ''
    local tbl = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000}

    for i = #tbl, 1, -1 do
        Decimal['_' .. tbl[i]] = math.floor(int / tbl[i])
        int = int - Decimal['_' .. tbl[i]] * tbl[i]
    end

    local switch = true
    local i = 1
    while i <= #tbl do
        local v = tbl[i]
        if (Decimal['_' .. v] == 4) then
            if switch then
                if Decimal['_' .. tbl[i + 1]] == 1 then
                    str = Roman['_' .. v] .. Roman['_' .. tbl[i + 2]] .. str
                    i = i + 1
                    switch = not switch
                else
                    str = Roman['_' .. v] .. Roman['_' .. tbl[i + 1]] .. str
                end
            else
                str = Roman['_' .. v] .. Roman['_' .. tbl[i + 1]] .. str
            end
        else
            for j = 1, Decimal['_' .. v] do
                str = Roman['_' .. v] .. str
            end
        end
        i = i + 1
        switch = not switch
    end

    return str
end

Value = 0

function Scroll(und)
    if und == 1 then
        Value = Value <= 399999 and Value + 1 or Value
    elseif und == -1 then
        Value = Value > 0 and Value - 1 or 0
	elseif und > 0 then 
	    Value = und
    end
---@diagnostic disable-next-line: undefined-global
    SKIN:Bang('!Update')
end

function Calculate(und)
	if und >= 0 and und <= 399999 then 
	    Value = und
	else
		Value = 1
    end
---@diagnostic disable-next-line: undefined-global
    SKIN:Bang('!Update')
end

function Update()
    -- Value = Value + 1
    if Value == 0 then return 'NULLA' end
    return IntToRoman(Value)
end