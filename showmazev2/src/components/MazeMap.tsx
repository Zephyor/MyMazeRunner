import React from 'react';
import MazeCell from "./MazeCell";
import './MazeMap.css';

interface MazeMapProps {
    content: string
}

const MazeMap = (props:MazeMapProps) => {
    const fileContent:string = props.content;
    const fileLines:string[] = fileContent.split(/\r?\n/);

    return (
        <div className='maze-map'>
            {
                fileLines.map((line, index) => {
                    return (
                        <div key={index} className='maze-row'>
                            {
                                [...line].map((char, index) => {
                                    return <MazeCell key={index} content={char}/>;
                                })
                            }
                        </div>
                    );
                })
            }
        </div>
    );
}

export default MazeMap;