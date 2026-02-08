#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                   ADVANCED PUSH_SWAP TESTER - ALL CASES                      #
#                                                                              #
# **************************************************************************** #

# Colors
PINK='\033[38;5;213m'
MINT='\033[38;5;158m'
PEACH='\033[38;5;217m'
PURPLE='\033[38;5;141m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Banner
clear
echo ""
echo -e "${PINK}╔══════════════════════════════════════════════════════╗${RESET}"
echo -e "${PINK}║                                                      ║${RESET}"
echo -e "${PINK}║      ${PURPLE}✧･ﾟ PUSH_SWAP ADVANCED TESTER ･ﾟ✧${PINK}          ║${RESET}"
echo -e "${PINK}║                                                      ║${RESET}"
echo -e "${PINK}╚══════════════════════════════════════════════════════╝${RESET}"
echo ""

# Check if push_swap exists
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}✗ Error: push_swap not found!${RESET}"
    echo -e "${YELLOW}Run 'make' first!${RESET}"
    exit 1
fi

# Test function
run_test() {
    local name="$1"
    local input="$2"
    local expected_type="$3"  # "error", "empty", "moves", "max_moves"
    local max_moves="$4"
    
    TOTAL=$((TOTAL + 1))
    
    printf "${PEACH}%-50s${RESET}" "$name"
    
    if [ "$expected_type" == "error" ]; then
        result=$(./push_swap $input 2>&1)
        if echo "$result" | grep -q "Error"; then
            echo -e "${MINT}✓ PASS${RESET}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL${RESET}"
            FAILED=$((FAILED + 1))
        fi
    elif [ "$expected_type" == "empty" ]; then
        result=$(./push_swap $input 2>&1)
        if [ -z "$result" ]; then
            echo -e "${MINT}✓ PASS${RESET}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL (expected no output)${RESET}"
            FAILED=$((FAILED + 1))
        fi
    elif [ "$expected_type" == "moves" ]; then
        result=$(./push_swap $input 2>&1)
        if [ ! -z "$result" ] && ! echo "$result" | grep -q "Error"; then
            echo -e "${MINT}✓ PASS${RESET}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL${RESET}"
            FAILED=$((FAILED + 1))
        fi
    elif [ "$expected_type" == "max_moves" ]; then
        result=$(./push_swap $input 2>&1)
        moves=$(echo "$result" | wc -l | tr -d ' ')
        if [ "$moves" -le "$max_moves" ]; then
            echo -e "${MINT}✓ PASS (${moves}/${max_moves})${RESET}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL (${moves}/${max_moves})${RESET}"
            FAILED=$((FAILED + 1))
        fi
    fi
}

# ============================= ERROR TESTS ===================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  ERROR TESTS${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "Non-numeric argument" "1 2 three" "error"
run_test "Duplicate numbers" "1 2 2 3" "error"
run_test "Number too big (> INT_MAX)" "1 2 2147483648" "error"
run_test "Number too small (< INT_MIN)" "1 2 -2147483649" "error"
run_test "Invalid characters" "1 2 3a" "error"

echo ""

# ========================== ALREADY SORTED TESTS =============================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  ALREADY SORTED TESTS (should output nothing)${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "Single number" "42" "empty"
run_test "Two sorted" "1 2" "empty"
run_test "Three sorted" "1 2 3" "empty"
run_test "Five sorted" "1 2 3 4 5" "empty"
run_test "Sorted with negatives" "-5 -3 0 2 8" "empty"

echo ""

# ============================= SIZE 2 TESTS ==================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  SIZE 2 TESTS (max 1 move)${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "Two reverse" "2 1" "max_moves" 1
run_test "Two negatives" "0 -1" "max_moves" 1

echo ""

# ============================= SIZE 3 TESTS ==================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  SIZE 3 TESTS (max 3 moves)${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "3 2 1" "3 2 1" "max_moves" 3
run_test "2 3 1" "2 3 1" "max_moves" 3
run_test "1 3 2" "1 3 2" "max_moves" 3
run_test "3 1 2" "3 1 2" "max_moves" 3
run_test "2 1 3" "2 1 3" "max_moves" 3

echo ""

# ============================= SIZE 5 TESTS ==================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  SIZE 5 TESTS (max 12 moves)${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "5 4 3 2 1 (reverse)" "5 4 3 2 1" "max_moves" 12
run_test "2 5 1 4 3 (random)" "2 5 1 4 3" "max_moves" 12
run_test "2 1 3 4 5 (almost sorted)" "2 1 3 4 5" "max_moves" 12
run_test "1 2 5 3 4 (one out)" "1 2 5 3 4" "max_moves" 12

echo ""

# ============================= EDGE CASES ====================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  EDGE CASES${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

run_test "INT_MAX and INT_MIN" "2147483647 0 -2147483648" "moves"
run_test "All negative" "-1 -5 -2 -10 -3" "moves"
run_test "With zeros" "0 -1 1 -2 2" "moves"

echo ""

# ========================== SIZE 100 TESTS ===================================

echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${PURPLE}  SIZE 100 TESTS (testing 5 random sets)${RESET}"
echo -e "${PURPLE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

for i in {1..5}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    result=$(./push_swap $ARG 2>&1)
    moves=$(echo "$result" | wc -l | tr -d ' ')
    
    printf "${PEACH}%-50s${RESET}" "Random 100 #$i"
    
    if [ "$moves" -lt 700 ]; then
        echo -e "${MINT}✓ EXCELLENT (${moves} moves) ⭐⭐⭐⭐⭐${RESET}"
        PASSED=$((PASSED + 1))
    elif [ "$moves" -lt 900 ]; then
        echo -e "${GREEN}✓ GOOD (${moves} moves) ⭐⭐⭐⭐${RESET}"
        PASSED=$((PASSED + 1))
    elif [ "$moves" -lt 1100 ]; then
        echo -e "${YELLOW}○ OK (${moves} moves) ⭐⭐⭐${RESET}"
        PASSED=$((PASSED + 1))
    elif [ "$moves" -lt 1500 ]; then
        echo -e "${YELLOW}△ ACCEPTABLE (${moves} moves) ⭐⭐${RESET}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ FAIL (${moves} moves - too many!)${RESET}"
        FAILED=$((FAILED + 1))
    fi
    
    TOTAL=$((TOTAL + 1))
done

echo ""

# ============================= SUMMARY =======================================

echo -e "${PINK}╔══════════════════════════════════════════════════════╗${RESET}"
echo -e "${PINK}║                     RESULTS                          ║${RESET}"
echo -e "${PINK}╚══════════════════════════════════════════════════════╝${RESET}"
echo ""
echo -e "${PURPLE}Total tests: ${TOTAL}${RESET}"
echo -e "${MINT}Passed: ${PASSED}${RESET}"
echo -e "${RED}Failed: ${FAILED}${RESET}"
echo ""

PERCENTAGE=$((PASSED * 100 / TOTAL))

if [ $FAILED -eq 0 ]; then
    echo -e "${MINT}✨ Perfect score! All tests passed! ✨${RESET}"
    echo -e "${PINK}⋆｡‧˚ʚ♡ɞ˚‧｡⋆ You're amazing! ⋆｡‧˚ʚ♡ɞ˚‧｡⋆${RESET}"
elif [ $PERCENTAGE -ge 80 ]; then
    echo -e "${GREEN}✓ Great job! ${PERCENTAGE}% passed!${RESET}"
    echo -e "${PEACH}Keep going, you're doing well! 💕${RESET}"
else
    echo -e "${YELLOW}⚠ ${PERCENTAGE}% passed - needs improvement${RESET}"
    echo -e "${PEACH}Don't give up! You got this! 💪${RESET}"
fi

echo ""