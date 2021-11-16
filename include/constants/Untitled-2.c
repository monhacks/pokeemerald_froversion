
SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);



token 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


I would probably just add an `if` statement to `static void MulByTypeEffectiveness` in `src/battle_util.c`

```if (gBattleMoves[move].effect == EFFECT_FALSE_SWIPE)
        mod = UQ_4_12(1.0);```


Riptoryps

**Type: Fire/Dragon**

Learnset

Well… that’s an organizational issue they ought to fix
If you change the incbin to say .bin.lz, or .bin.whatever compression it uses, you can then rename the file to how it’s supposed to be and decompress it with gbagfx
tools/gbagfx/gbagfx path/to/compressed/file.bin.lz path/to/compressed/file.bin
Gbagfx relies on file extensions to do its job, so the rename is required if you were to do that 
