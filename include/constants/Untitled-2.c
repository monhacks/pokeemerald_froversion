
SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);



token 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


I would probably just add an `if` statement to `static void MulByTypeEffectiveness` in `src/battle_util.c`

```if (gBattleMoves[move].effect == EFFECT_FALSE_SWIPE)
        mod = UQ_4_12(1.0);```


Riptoryps

**Type: Fire/Dragon**

Learnset