import React from 'react';

interface MazeCellProps {
    content: string
}

const MazeCell = (props:MazeCellProps) => {

    let cellTypeStyle;

    switch (props.content) {
        case '*':
            cellTypeStyle = 'cell-empty';
            break;
        case 'X':
            cellTypeStyle = 'cell-wall';
            break;
        case 'o':
            cellTypeStyle = 'cell-path';
            break;
        default:
            cellTypeStyle = '';
    }

    return (
        <div className={`maze-cell ${cellTypeStyle}`}>
            
        </div>
    );
}

export default MazeCell;