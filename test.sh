#!/bin/bash

# Цвета ANSI
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
NC='\033[0m' # No Color

# Параметры
COUNT=${1:-100}
SIZE=${2:-5}

ok=0
ko=0
err=0
total_instr=0
min_instr=99999
max_instr=0

echo -e "${BLUE}Запускаем $COUNT тестов с $SIZE элементами...${NC}"
echo "---------------------------"

for ((i=1; i<=COUNT; i++))
do
	ARGS=$(shuf -i 0-1000 -n $SIZE | tr '\n' ' ')
	INSTRUCTIONS=$(./push_swap $ARGS)
	RESULT=$(echo "$INSTRUCTIONS" | ./checker_linux $ARGS)
	NUM=$(echo "$INSTRUCTIONS" | wc -l)
	total_instr=$((total_instr + NUM))
	(( NUM < min_instr )) && min_instr=$NUM
	(( NUM > max_instr )) && max_instr=$NUM

	case $RESULT in
		"OK") ((ok++)); COLOR=$GREEN;;
		"KO") ((ko++)); COLOR=$RED;;
		*) ((err++)); COLOR=$YELLOW;;
	esac

	# Прогресс с цветом
	printf "\r[%-50s] %d/%d ${GREEN}OK:%d${NC} ${RED}KO:%d${NC} ${YELLOW}ERR:%d${NC}" \
	"$(printf '#%.0s' $(seq 1 $((i * 50 / COUNT))))" "$i" "$COUNT" "$ok" "$ko" "$err"
done

# Отчёт
echo
echo -e "${BLUE}============================${NC}"
echo -e "${GREEN}✔ OK:       $ok${NC}"
echo -e "${RED}✘ KO:       $ko${NC}"
echo -e "${YELLOW}⚠ Error:    $err${NC}"
echo -e "${BLUE}📊 Среднее кол-во инструкций: $((total_instr / COUNT))${NC}"
echo -e "${BLUE}🔻 Мин. инструкций: $min_instr${NC}"
echo -e "${BLUE}🔺 Макс. инструкций: $max_instr${NC}"
